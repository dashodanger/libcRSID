//------------------------------------------------------------------------------
//  m4player-sapp.c
//  sokol_app + sokol_audio + mod4play
//  This uses the user-data callback model both for sokol_app.h and
//  sokol_audio.h
//------------------------------------------------------------------------------

#define SOKOL_IMPL
#include "sokol/sokol_app.h"
#include "sokol/sokol_gfx.h"
#include "sokol/sokol_audio.h"
#include "sokol/sokol_log.h"
#include "sokol/sokol_glue.h"
#define CRSID_IMPLEMENTATION
#include "../libcRSID.h"
#include "data/Edge_of_Disgrace.h"
#include <assert.h>
#include <stdint.h>
#include <string.h>

static cRSID_C64instance *sidplayer_c64 = NULL;
static cRSID_SIDheader *sidplayer_header = NULL;
static int      user_sid_size = 0;
static uint8_t *user_sid_buffer = NULL;

// common function to read sample stream from mod4play and convert to float
static void read_samples(float* buffer, int num_samples) {
    // NOTE: for multi-channel playback, the samples are interleaved
    // (e.g. left/right/left/right/...)
    cRSID_generateFloat(sidplayer_c64, buffer, (unsigned short)num_samples*sizeof(float));
}

// stream callback, called by sokol_audio when new samples are needed,
// on most platforms, this runs on a separate thread
static void stream_cb(float* buffer, int num_frames, int num_channels, void* user_data) {
    const int num_samples = num_frames * num_channels;
    read_samples(buffer, num_samples);
}

static void init(void* user_data) {
    // setup sokol_gfx
    sg_setup(&(sg_desc){
        .context = sapp_sgcontext(),
        .logger.func = slog_func,
    });

    sidplayer_c64 = cRSID_init(44100);
    if (sidplayer_c64)
    {
        if (user_sid_buffer != NULL)
            sidplayer_header = cRSID_processSIDfile(sidplayer_c64, user_sid_buffer, user_sid_size);
        else
            sidplayer_header = cRSID_processSIDfile(sidplayer_c64, edge_of_disgrace, sizeof(edge_of_disgrace));
    }
    if (sidplayer_header)
    {
        cRSID_initSIDtune(sidplayer_c64, sidplayer_header, 0);
    }

    // setup sokol_audio (default sample rate is 44100Hz)
    saudio_setup(&(saudio_desc){
        .num_channels = 2,
        .stream_userdata_cb = stream_cb,
        .logger.func = slog_func,
    });
}

static void frame(void* user_data) {
    (void)user_data;
    sg_pass_action pass_action = {
        .colors[0] = { .load_action = SG_LOADACTION_CLEAR, .clear_value = { 0.4f, 0.7f, 1.0f, 1.0f } }
    };
    sg_begin_default_pass(&pass_action, sapp_width(), sapp_height());
    sg_end_pass();
    sg_commit();
}

static void cleanup(void* user_data) {
    (void)user_data;
    saudio_shutdown();
    cRSID_initC64(sidplayer_c64);
    sidplayer_c64 = NULL;
    if (user_sid_buffer)
    {
        sidplayer_header = NULL;
        free(user_sid_buffer);
        user_sid_buffer = NULL;
        user_sid_size = 0;
    }
    sg_shutdown();
}

sapp_desc sokol_main(int argc, char* argv[]) {
    // Really simple, assumes the first argument passed is a filename to open;
    // make something more robust for the real world
    if (argc > 1)
    {
        FILE *user_sid_file = fopen(argv[1], "rb");
        if (user_sid_file != NULL)
        {
            long cur_pos = ftell(user_sid_file);
            fseek(user_sid_file, 0, SEEK_END);
            user_sid_size = (int)ftell(user_sid_file);
            fseek(user_sid_file, cur_pos, SEEK_SET);
            if (user_sid_size > 0)
            {
                user_sid_buffer = (uint8_t *)calloc(user_sid_size, 1);
                if (fread(user_sid_buffer, 1, user_sid_size, user_sid_file) != user_sid_size)
                {
                    free(user_sid_buffer);
                    user_sid_buffer = NULL;
                    user_sid_size = 0;
                }
            }
            fclose(user_sid_file);
            user_sid_file = NULL;
        }
    }
    return (sapp_desc){
        .init_userdata_cb = init,
        .frame_userdata_cb = frame,
        .cleanup_userdata_cb = cleanup,
        .user_data = NULL,
        .width = 400,
        .height = 300,
        .window_title = "Sokol Audio + libcRSID",
        .icon.sokol_default = true,
        .logger.func = slog_func,
    };
}
