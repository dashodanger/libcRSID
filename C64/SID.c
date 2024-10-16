
// cRSID SID emulation engine

void cRSID_createSIDchip(cRSID_C64instance *C64, cRSID_SIDinstance *SID, unsigned short model, char channel,
                         unsigned short baseaddress)
{
    SID->C64       = C64;
    SID->ChipModel = model;
    SID->Channel   = channel;
    if (baseaddress >= 0xD400 && (baseaddress < 0xD800 || (0xDE00 <= baseaddress && baseaddress <= 0xDFE0)))
    { // check valid address, avoid Color-RAM
        SID->BaseAddress = baseaddress;
        SID->BasePtr     = &C64->IObankWR[baseaddress];
    }
    else
    {
        SID->BaseAddress = 0x0000;
        SID->BasePtr     = 0;
    }
    cRSID_initSIDchip(SID);
}

void cRSID_initSIDchip(cRSID_SIDinstance *SID)
{
    static unsigned char Channel;
    for (Channel = 0; Channel < 21; Channel += 7)
    {
        SID->ADSRstate[Channel]       = 0;
        SID->RateCounter[Channel]     = 0;
        SID->EnvelopeCounter[Channel] = 0;
        SID->ExponentCounter[Channel] = 0;
        SID->PhaseAccu[Channel]       = 0;
        SID->PrevPhaseAccu[Channel]   = 0;
        SID->NoiseLFSR[Channel]       = 0x7FFFFF;
        SID->PrevWavGenOut[Channel]   = 0;
        SID->PrevWavData[Channel]     = 0;
    }
    SID->SyncSourceMSBrise = 0;
    SID->RingSourceMSB     = 0;
    SID->PrevLowPass = SID->PrevBandPass = SID->PrevVolume = 0;
}

void cRSID_emulateADSRs(cRSID_SIDinstance *SID, char cycles)
{

    enum ADSRstateBits
    {
        GATE_BITVAL         = 0x01,
        ATTACK_BITVAL       = 0x80,
        DECAYSUSTAIN_BITVAL = 0x40,
        HOLDZEROn_BITVAL    = 0x10
    };

    static const short         ADSRprescalePeriods[16] = {9,   32,  63,   95,   149,  220,   267,   313,
                                                          392, 977, 1954, 3126, 3907, 11720, 19532, 31251};
    static const unsigned char ADSRexponentPeriods[256] =
        {1, 30, 30, 30, 30, 30, 30, 16, 16, 16, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
         4, 4,  4,  4,  4,                     // pos0:1  pos6:30  pos14:16  pos26:8
         4, 4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2,
         2, 2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
         2, 2,  2,  2,  2,  2,  2,  2,  1,  1, // pos54:4 //pos93:2
         1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
         1, 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    static unsigned char   Channel, PrevGate, AD, SR;
    static unsigned short  PrescalePeriod;
    static unsigned char  *ChannelPtr, *ADSRstatePtr, *EnvelopeCounterPtr, *ExponentCounterPtr;
    static unsigned short *RateCounterPtr;

    for (Channel = 0; Channel < 21; Channel += 7)
    {

        ChannelPtr         = &SID->BasePtr[Channel];
        AD                 = ChannelPtr[5];
        SR                 = ChannelPtr[6];
        ADSRstatePtr       = &(SID->ADSRstate[Channel]);
        RateCounterPtr     = &(SID->RateCounter[Channel]);
        EnvelopeCounterPtr = &(SID->EnvelopeCounter[Channel]);
        ExponentCounterPtr = &(SID->ExponentCounter[Channel]);

        PrevGate = (*ADSRstatePtr & GATE_BITVAL);
        if (PrevGate != (ChannelPtr[4] & GATE_BITVAL))
        {                                                                              // gatebit-change?
            if (PrevGate)
                *ADSRstatePtr &= ~(GATE_BITVAL | ATTACK_BITVAL | DECAYSUSTAIN_BITVAL); // falling edge
            else
                *ADSRstatePtr = (GATE_BITVAL | ATTACK_BITVAL | DECAYSUSTAIN_BITVAL | HOLDZEROn_BITVAL); // rising edge
        }

        if (*ADSRstatePtr & ATTACK_BITVAL)
            PrescalePeriod = ADSRprescalePeriods[AD >> 4];
        else if (*ADSRstatePtr & DECAYSUSTAIN_BITVAL)
            PrescalePeriod = ADSRprescalePeriods[AD & 0x0F];
        else
            PrescalePeriod = ADSRprescalePeriods[SR & 0x0F];

        *RateCounterPtr += cycles;
        if (*RateCounterPtr >= 0x8000)
            *RateCounterPtr -= 0x8000; //*RateCounterPtr &= 0x7FFF; //can wrap around (ADSR delay-bug: short 1st frame)

        if (PrescalePeriod <= *RateCounterPtr && *RateCounterPtr < PrescalePeriod + cycles)
        {                              // ratecounter shot (matches rateperiod) (in genuine SID ratecounter is LFSR)
            *RateCounterPtr -= PrescalePeriod; // reset rate-counter on period-match
            if ((*ADSRstatePtr & ATTACK_BITVAL) || ++(*ExponentCounterPtr) == ADSRexponentPeriods[*EnvelopeCounterPtr])
            {
                *ExponentCounterPtr = 0;
                if (*ADSRstatePtr & HOLDZEROn_BITVAL)
                {
                    if (*ADSRstatePtr & ATTACK_BITVAL)
                    {
                        ++(*EnvelopeCounterPtr);
                        if (*EnvelopeCounterPtr == 0xFF)
                            *ADSRstatePtr &= ~ATTACK_BITVAL;
                    }
                    else if (!(*ADSRstatePtr & DECAYSUSTAIN_BITVAL) || *EnvelopeCounterPtr != (SR & 0xF0) + (SR >> 4))
                    {
                        --(*EnvelopeCounterPtr); // resid adds 1 cycle delay, we omit that mechanism here
                        if (*EnvelopeCounterPtr == 0)
                            *ADSRstatePtr &= ~HOLDZEROn_BITVAL;
                    }
                }
            }
        }
    }
}

#include "SIDwaves.h"

static unsigned short combinedWF(cRSID_SIDinstance *SID, unsigned char *ChannelPtr, unsigned char Channel,
                                 const unsigned char *WFarray, unsigned short oscval)
{
    static unsigned char  Pitch;
    static unsigned short Filt;
    if (SID->ChipModel == 6581 && WFarray != PulseTriangle)
        oscval &= 0x7FFF;
    Pitch                     = ChannelPtr[1] ? ChannelPtr[1] : 1; // avoid division by zero
    Filt                      = 0x7777 + (0x8888 / Pitch);
    SID->PrevWavData[Channel] = (WFarray[oscval >> 4] * Filt + SID->PrevWavData[Channel] * (0xFFFF - Filt)) >> 16;
    return SID->PrevWavData[Channel] << 8;
}

int cRSID_emulateWaves(cRSID_SIDinstance *SID)
{
    enum WaveFormBits
    {
        NOISE_BITVAL = 0x80,
        PULSE_BITVAL = 0x40,
        SAW_BITVAL   = 0x20,
        TRI_BITVAL   = 0x10
    };
    enum ControlBits
    {
        TEST_BITVAL = 0x08,
        RING_BITVAL = 0x04,
        SYNC_BITVAL = 0x02,
        GATE_BITVAL = 0x01
    };
    enum FilterBits
    {
        OFF3_BITVAL = 0x80
    };

    static const unsigned char FilterSwitchVal[] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 4};

    static char          MainVolume;
    static unsigned char Channel, WF, TestBit, Envelope, FilterSwitchReso, VolumeBand;
    static unsigned int  Utmp, PhaseAccuStep, MSB, WavGenOut, PW;
    static int           Tmp, Feedback, Steepness, PulsePeak;
    // static int FilterInput, Cutoff, Resonance, FilterOutput, NonFilted, Output;
    static unsigned char *ChannelPtr;
    static int           *PhaseAccuPtr;

    SID->NonFiltedSample = SID->FilterInputSample = 0;
    FilterSwitchReso                              = SID->BasePtr[0x17];
    VolumeBand                                    = SID->BasePtr[0x18];

    // Waveform-generator //(phase accumulator and waveform-selector)

    for (Channel = 0; Channel < 21; Channel += 7)
    {
        ChannelPtr = &(SID->BasePtr[Channel]);

        WF           = ChannelPtr[4];
        TestBit      = ((WF & TEST_BITVAL) != 0);
        PhaseAccuPtr = &(SID->PhaseAccu[Channel]);

        PhaseAccuStep = ((ChannelPtr[1] << 8) + ChannelPtr[0]) * SID->C64->SampleClockRatio;
        if (TestBit || ((WF & SYNC_BITVAL) && SID->SyncSourceMSBrise))
            *PhaseAccuPtr = 0;
        else
        { // stepping phase-accumulator (oscillator)
            *PhaseAccuPtr += PhaseAccuStep;
            if (*PhaseAccuPtr >= 0x10000000)
                *PhaseAccuPtr -= 0x10000000;
        }
        *PhaseAccuPtr &= 0xFFFFFFF;
        MSB                    = *PhaseAccuPtr & 0x8000000;
        SID->SyncSourceMSBrise = (MSB > (SID->PrevPhaseAccu[Channel] & 0x8000000)) ? 1 : 0;

        if (WF & NOISE_BITVAL)
        {                                  // noise waveform
            Tmp = SID->NoiseLFSR[Channel]; // clock LFSR all time if clockrate exceeds observable at given samplerate
                                           // (last term):
            if (((*PhaseAccuPtr & 0x1000000) != (SID->PrevPhaseAccu[Channel] & 0x1000000)) ||
                PhaseAccuStep >= 0x1000000)
            {
                Feedback = ((Tmp & 0x400000) ^ ((Tmp & 0x20000) << 5)) != 0;
                Tmp      = ((Tmp << 1) | Feedback | TestBit) &
                      0x7FFFFF; // TEST-bit turns all bits in noise LFSR to 1 (on real SID slowly, in approx. 8000
                                // microseconds ~ 300 samples)
                SID->NoiseLFSR[Channel] = Tmp;
            } // we simply zero output when other waveform is mixed with noise. On real SID LFSR continuously gets
              // filled by zero and locks up. ($C1 waveform with pw<8 can keep it for a while.)
            WavGenOut = (WF & 0x70) ? 0
                                    : ((Tmp & 0x100000) >> 5) | ((Tmp & 0x40000) >> 4) | ((Tmp & 0x4000) >> 1) |
                                          ((Tmp & 0x800) << 1) | ((Tmp & 0x200) << 2) | ((Tmp & 0x20) << 5) |
                                          ((Tmp & 0x04) << 7) | ((Tmp & 0x01) << 8);
        }

        else if (WF & PULSE_BITVAL)
        {                                                               // simple pulse
            PW   = (((ChannelPtr[3] & 0xF) << 8) + ChannelPtr[2]) << 4; // PW=0000..FFF0 from SID-register
            Utmp = (int)(PhaseAccuStep >> 13);
            if (0 < PW && PW < Utmp)
                PW = Utmp;                                              // Too thin pulsewidth? Correct...
            Utmp ^= 0xFFFF;
            if (PW > Utmp)
                PW = Utmp; // Too thin pulsewidth? Correct it to a value representable at the current samplerate
            Utmp = *PhaseAccuPtr >> 12;

            if ((WF & 0xF0) == PULSE_BITVAL)
            { // simple pulse, most often used waveform, make it sound as clean as possible (by making it trapezoid)
                Steepness = (PhaseAccuStep >= 4096) ? 0xFFFFFFF / PhaseAccuStep
                                                    : 0xFFFF; // rising/falling-edge steepness (add/sub at samples)
                if (TestBit)
                    WavGenOut = 0xFFFF;
                else if (Utmp < PW)
                {                  // rising edge (interpolation)
                    PulsePeak =
                        (0xFFFF - PW) *
                        Steepness; // very thin pulses don't make a full swing between 0 and max but make a little spike
                    if (PulsePeak > 0xFFFF)
                        PulsePeak = 0xFFFF; // but adequately thick trapezoid pulses reach the maximum level
                    Tmp       = PulsePeak - (PW - Utmp) * Steepness; // draw the slope from the peak
                    WavGenOut = (Tmp < 0) ? 0 : Tmp;                 // but stop at 0-level
                }
                else
                {                                                    // falling edge (interpolation)
                    PulsePeak =
                        PW *
                        Steepness; // very thin pulses don't make a full swing between 0 and max but make a little spike
                    if (PulsePeak > 0xFFFF)
                        PulsePeak = 0xFFFF; // adequately thick trapezoid pulses reach the maximum level
                    Tmp       = (0xFFFF - Utmp) * Steepness - PulsePeak; // draw the slope from the peak
                    WavGenOut = (Tmp >= 0) ? 0xFFFF : Tmp;               // but stop at max-level
                }
            }

            else
            { // combined pulse
                WavGenOut = (Utmp >= PW || TestBit) ? 0xFFFF : 0;
                if (WF & TRI_BITVAL)
                {
                    if (WF & SAW_BITVAL)
                    { // pulse+saw+triangle (waveform nearly identical to tri+saw)
                        if (WavGenOut)
                            WavGenOut = combinedWF(SID, ChannelPtr, Channel, PulseSawTriangle, Utmp);
                    }
                    else
                    { // pulse+triangle
                        Tmp = *PhaseAccuPtr ^ ((WF & RING_BITVAL) ? SID->RingSourceMSB : 0);
                        if (WavGenOut)
                            WavGenOut = combinedWF(SID, ChannelPtr, Channel, PulseTriangle, Tmp >> 12);
                    }
                }
                else if (WF & SAW_BITVAL)
                { // pulse+saw
                    if (WavGenOut)
                        WavGenOut = combinedWF(SID, ChannelPtr, Channel, PulseSawtooth, Utmp);
                }
            }
        }

        else if (WF & SAW_BITVAL)
        {                                    // sawtooth
            WavGenOut = *PhaseAccuPtr >> 12; // saw (this row would be enough for simple but aliased-at-high-pitch saw)
            if (WF & TRI_BITVAL)
                WavGenOut = combinedWF(SID, ChannelPtr, Channel, SawTriangle, WavGenOut); // saw+triangle
            else
            {                                         // simple cleaned (bandlimited) saw
                Steepness = (PhaseAccuStep >> 4) / 288;
                if (Steepness == 0)
                    Steepness = 1;                    // avoid division by zero in next steps
                WavGenOut +=
                    (WavGenOut * Steepness) >> 16;    // 1st half (rising edge) of asymmetric triangle-like saw waveform
                if (WavGenOut > 0xFFFF)
                    WavGenOut = 0xFFFF - (((WavGenOut - 0x10000) << 16) /
                                          Steepness); // 2nd half (falling edge, reciprocal steepness)
            }
        }

        else if (WF & TRI_BITVAL)
        { // triangle (this waveform has no harsh edges, so it doesn't suffer from strong aliasing at high pitches)
            Tmp       = *PhaseAccuPtr ^ (WF & RING_BITVAL ? SID->RingSourceMSB : 0);
            WavGenOut = (Tmp ^ (Tmp & 0x8000000 ? 0xFFFFFFF : 0)) >> 11;
        }

        WavGenOut &= 0xFFFF;
        if (WF & 0xF0)
            SID->PrevWavGenOut[Channel] =
                WavGenOut; // emulate waveform 00 floating wave-DAC (utilized by SounDemon digis)
        else
            WavGenOut = SID->PrevWavGenOut[Channel]; //(on real SID waveform00 decays, we just simply keep the value to
                                                     //avoid clicks)
        SID->PrevPhaseAccu[Channel] = *PhaseAccuPtr;
        SID->RingSourceMSB          = MSB;

        // routing the channel signal to either the filter or the unfiltered master output depending on filter-switch
        // SID-registers
        Envelope =
            SID->ChipModel == 8580 ? SID->EnvelopeCounter[Channel] : ADSR_DAC_6581[SID->EnvelopeCounter[Channel]];
        if (FilterSwitchReso & FilterSwitchVal[Channel])
        {
            SID->FilterInputSample += (((int)WavGenOut - 0x8000) * Envelope) >> 8;
        }
        else if (Channel != 14 || !(VolumeBand & OFF3_BITVAL))
        {
            SID->NonFiltedSample += (((int)WavGenOut - 0x8000) * Envelope) >> 8;
        }
    }
    // update readable SID1-registers (some SID tunes might use 3rd channel ENV3/OSC3 value as control)
    SID->C64->IObankRD[SID->BaseAddress + 0x1B] =
        WavGenOut >> 8; // OSC3, ENV3 (some players rely on it, unfortunately even for timing)
    SID->C64->IObankRD[SID->BaseAddress + 0x1C] = SID->EnvelopeCounter[14]; // Envelope

    return cRSID_emulateSIDoutputStage(SID);
}

static inline int cRSID_emulateSIDoutputStage(cRSID_SIDinstance *SID)
{
    enum SIDspecs
    {
        CHANNELS         = 3 + 1,
        VOLUME_MAX       = 0xF,
        D418_DIGI_VOLUME = 2
    }; // digi-channel is counted too
    enum FilterBits
    {
        OFF3_BITVAL     = 0x80,
        HIGHPASS_BITVAL = 0x40,
        BANDPASS_BITVAL = 0x20,
        LOWPASS_BITVAL  = 0x10
    };
#include "SIDfilter.h"

    static char          MainVolume;
    static unsigned char FilterSwitchReso, VolumeBand;
    static int           Tmp, NonFilted, FilterInput, Cutoff, Resonance, FilterOutput, Output;

    FilterSwitchReso = SID->BasePtr[0x17];
    VolumeBand       = SID->BasePtr[0x18];
    Cutoff           = (SID->BasePtr[0x16] << 3) + (SID->BasePtr[0x15] & 7);
    Resonance        = FilterSwitchReso >> 4;

    NonFilted   = SID->NonFiltedSample;
    FilterInput = SID->FilterInputSample;

    // Filter

    if (SID->ChipModel == 8580)
    {
        Cutoff    = CutoffMul8580_44100Hz[Cutoff];
        Resonance = Resonances8580[Resonance];
    }
    else
    { // 6581
        Cutoff += (FilterInput * 105) >> 16;
        if (Cutoff > 0x7FF)
            Cutoff = 0x7FF;
        else if (Cutoff < 0)
            Cutoff = 0;                            // MOSFET-VCR control-voltage calculation
        Cutoff    = CutoffMul6581_44100Hz[Cutoff]; //(resistance-modulation aka 6581 filter distortion) emulation
        Resonance = Resonances6581[Resonance];
    }

    FilterOutput = 0;
    Tmp          = FilterInput + ((SID->PrevBandPass * Resonance) >> 12) + SID->PrevLowPass;
    if (VolumeBand & HIGHPASS_BITVAL)
        FilterOutput -= Tmp;
    Tmp               = SID->PrevBandPass - ((Tmp * Cutoff) >> 12);
    SID->PrevBandPass = Tmp;
    if (VolumeBand & BANDPASS_BITVAL)
        FilterOutput -= Tmp;
    Tmp              = SID->PrevLowPass + ((Tmp * Cutoff) >> 12);
    SID->PrevLowPass = Tmp;
    if (VolumeBand & LOWPASS_BITVAL)
        FilterOutput += Tmp;

    // Output-mixing stage

    // For $D418 volume-register digi playback: an AC / DC separation for $D418 value at low (20Hz or so)
    // cutoff-frequency, sending AC (highpass) value to a 4th 'digi' channel mixed to the master output, and set ONLY
    // the DC (lowpass) value to the volume-control. This solved 2 issues: Thanks to the lowpass filtering of the
    // volume-control, SID tunes where digi is played together with normal SID channels, won't sound distorted anymore,
    // and the volume-clicks disappear when setting SID-volume. (This is useful for fade-in/out tunes like Hades Nebula,
    // where clicking ruins the intro.)
    if (SID->C64->RealSIDmode)
    {
        Tmp = (signed int)((VolumeBand & 0xF) << 12);
        NonFilted += (Tmp - SID->PrevVolume) *
                     D418_DIGI_VOLUME; // highpass is digi, adding it to output must be before digifilter-code
        SID->PrevVolume += (Tmp - SID->PrevVolume) >> 10; // arithmetic shift amount determines digi lowpass-frequency
        MainVolume = SID->PrevVolume >> 12;               // lowpass is main volume
    }
    else
        MainVolume = VolumeBand & 0xF;

    SID->Output = ((NonFilted + FilterOutput) * MainVolume);

    Output = SID->Output / ((CHANNELS * VOLUME_MAX) + SID->C64->Attenuation);

    return Output; // master output of a SID
}

//----------------------- High-quality (oversampled) waveform-generation --------------------------

static unsigned short HQcombinedWF(cRSID_SIDinstance *SID, const unsigned char *WFarray, unsigned short oscval)
{
    if (SID->ChipModel == 6581 && WFarray != PulseTriangle)
        oscval &= 0x7FFF;
    return WFarray[oscval >> 4] << 8;
}

cRSID_SIDwavOutput cRSID_emulateHQwaves(cRSID_SIDinstance *SID, char cycles)
{
    enum WaveFormBits
    {
        NOISE_BITVAL = 0x80,
        PULSE_BITVAL = 0x40,
        SAW_BITVAL   = 0x20,
        TRI_BITVAL   = 0x10
    };
    enum ControlBits
    {
        TEST_BITVAL = 0x08,
        RING_BITVAL = 0x04,
        SYNC_BITVAL = 0x02,
        GATE_BITVAL = 0x01
    };
    enum FilterBits
    {
        OFF3_BITVAL = 0x80
    };

    static unsigned char Channel, WF, TestBit, Envelope, FilterSwitchReso, VolumeBand;
    static unsigned int  Utmp, PhaseAccuStep, MSB, WavGenOut, PW;
    static int           Tmp, Feedback;
    // static int FilterInput, Cutoff, Resonance; //, FilterOutput, NonFilted, Output;
    static unsigned char     *ChannelPtr;
    static int               *PhaseAccuPtr;
    static cRSID_SIDwavOutput SIDwavOutput;

    static const unsigned char FilterSwitchVal[] = {1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 4};

    SIDwavOutput.FilterInput = SIDwavOutput.NonFilted = 0;
    FilterSwitchReso                                  = SID->BasePtr[0x17];
    VolumeBand                                        = SID->BasePtr[0x18];

    for (Channel = 0; Channel < 21; Channel += 7)
    {
        ChannelPtr = &(SID->BasePtr[Channel]);

        WF           = ChannelPtr[4];
        TestBit      = ((WF & TEST_BITVAL) != 0);
        PhaseAccuPtr = &(SID->PhaseAccu[Channel]);

        PhaseAccuStep = ((ChannelPtr[1] << 8) + ChannelPtr[0]) * cycles;
        if (TestBit || ((WF & SYNC_BITVAL) && SID->SyncSourceMSBrise))
            *PhaseAccuPtr = 0;
        else
        { // stepping phase-accumulator (oscillator)
            *PhaseAccuPtr += PhaseAccuStep;
            if (*PhaseAccuPtr >= 0x1000000)
                *PhaseAccuPtr -= 0x1000000;
        }
        *PhaseAccuPtr &= 0xFFFFFF;
        MSB                    = *PhaseAccuPtr & 0x800000;
        SID->SyncSourceMSBrise = (MSB > (SID->PrevPhaseAccu[Channel] & 0x800000)) ? 1 : 0;

        if (WF & NOISE_BITVAL)
        {                                  // noise waveform
            Tmp = SID->NoiseLFSR[Channel]; // clock LFSR all time if clockrate exceeds observable at given samplerate
                                           // (last term):

            if (((*PhaseAccuPtr & 0x100000) != (SID->PrevPhaseAccu[Channel] & 0x100000)))
            {
                Feedback = ((Tmp & 0x400000) ^ ((Tmp & 0x20000) << 5)) != 0;
                Tmp      = ((Tmp << 1) | Feedback | TestBit) &
                      0x7FFFFF; // TEST-bit turns all bits in noise LFSR to 1 (on real SID slowly, in approx. 8000
                                // microseconds ~ 300 samples)
                SID->NoiseLFSR[Channel] = Tmp;
            } // we simply zero output when other waveform is mixed with noise. On real SID LFSR continuously gets
              // filled by zero and locks up. ($C1 waveform with pw<8 can keep it for a while.)
            WavGenOut = (WF & 0x70) ? 0
                                    : ((Tmp & 0x100000) >> 5) | ((Tmp & 0x40000) >> 4) | ((Tmp & 0x4000) >> 1) |
                                          ((Tmp & 0x800) << 1) | ((Tmp & 0x200) << 2) | ((Tmp & 0x20) << 5) |
                                          ((Tmp & 0x04) << 7) | ((Tmp & 0x01) << 8);
        }
        else if (WF & PULSE_BITVAL)
        {                                                                    // simple pulse or pulse+combined
            PW        = (((ChannelPtr[3] & 0xF) << 8) + ChannelPtr[2]) << 4; // PW=0000..FFF0 from SID-register
            Utmp      = *PhaseAccuPtr >> 8;
            WavGenOut = (Utmp >= PW || TestBit) ? 0xFFFF : 0;
            if ((WF & 0xF0) != PULSE_BITVAL)
            { // combined pulse
                if (WF & TRI_BITVAL)
                {
                    if (WF & SAW_BITVAL)
                    { // pulse+saw+triangle (waveform nearly identical to tri+saw)
                        if (WavGenOut)
                            WavGenOut = HQcombinedWF(SID, PulseSawTriangle, Utmp);
                    }
                    else
                    { // pulse+triangle
                        Tmp = *PhaseAccuPtr ^ ((WF & RING_BITVAL) ? SID->RingSourceMSB : 0);
                        if (WavGenOut)
                            WavGenOut = HQcombinedWF(SID, PulseTriangle, Tmp >> 8);
                    }
                }
                else if (WF & SAW_BITVAL)
                { // pulse+saw
                    if (WavGenOut)
                        WavGenOut = HQcombinedWF(SID, PulseSawtooth, Utmp);
                }
            }
        }
        else if (WF & SAW_BITVAL)
        {                                                              // sawtooth
            WavGenOut = *PhaseAccuPtr >> 8;
            if (WF & TRI_BITVAL)
                WavGenOut = HQcombinedWF(SID, SawTriangle, WavGenOut); // saw+triangle
        }
        else if (WF & TRI_BITVAL)
        { // triangle (this waveform has no harsh edges, so it doesn't suffer from strong aliasing at high pitches)
            Tmp       = *PhaseAccuPtr ^ (WF & RING_BITVAL ? SID->RingSourceMSB : 0);
            WavGenOut = (Tmp ^ (Tmp & 0x800000 ? 0xFFFFFF : 0)) >> 7;
        }

        WavGenOut &= 0xFFFF;
        if (WF & 0xF0)
            SID->PrevWavGenOut[Channel] =
                WavGenOut; // emulate waveform 00 floating wave-DAC (utilized by SounDemon digis)
        else
            WavGenOut = SID->PrevWavGenOut[Channel]; //(on real SID waveform00 decays, we just simply keep the value to
                                                     //avoid clicks)
        SID->PrevPhaseAccu[Channel] = *PhaseAccuPtr;
        SID->RingSourceMSB          = MSB;

        // routing the channel signal to either the filter or the unfiltered master output depending on filter-switch
        // SID-registers
        Envelope =
            SID->ChipModel == 8580 ? SID->EnvelopeCounter[Channel] : ADSR_DAC_6581[SID->EnvelopeCounter[Channel]];
        if (FilterSwitchReso & FilterSwitchVal[Channel])
        {
            SIDwavOutput.FilterInput += (((int)WavGenOut - 0x8000) * Envelope) >> 8;
        }
        else if (Channel != 14 || !(VolumeBand & OFF3_BITVAL))
        {
            SIDwavOutput.NonFilted += (((int)WavGenOut - 0x8000) * Envelope) >> 8;
        }
    }
    // update readable SID1-registers (some SID tunes might use 3rd channel ENV3/OSC3 value as control)
    SID->C64->IObankRD[SID->BaseAddress + 0x1B] =
        WavGenOut >> 8; // OSC3, ENV3 (some players rely on it, unfortunately even for timing)
    SID->C64->IObankRD[SID->BaseAddress + 0x1C] = SID->EnvelopeCounter[14]; // Envelope

    // SIDwavOutput.NonFilted=NonFilted; SIDwavOutput.FilterInput=FilterInput; //SID->FilterInputCycle=FilterInput;
    // //SID->NonFiltedCycle=NonFilted;
    return SIDwavOutput; // NonFilted; //+FilterInput; //WavGenOut; //(*PhaseAccuPtr)>>8;
}
