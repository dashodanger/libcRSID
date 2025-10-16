//------------------------------------------------------------------------------------------------
//  sidplayer.c
//  sokol_args + sokol_audio + libcRSID
//-------------------------------------------------------------------------------------------------
//
// Copyright (c) 2025 dashodanger
// Copyright (c) 2017 Andre Weissflog (original player example code)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//------------------------------------------------------------------------------------------------

#define SOKOL_IMPL
#include "sokol/sokol_args.h"
#include "sokol/sokol_audio.h"
#include "sokol/sokol_log.h"
#define CRSID_IMPLEMENTATION
#include "../libcRSID.h"
#include "data/Edge_of_Disgrace.h"
#include <stdint.h>
#include <string.h>

static cRSID_C64instance *sidplayer_c64 = NULL;
static bool sid_playing = false;

// stream callback, called by sokol_audio when new samples are needed,
// on most platforms, this runs on a separate thread
static void stream_cb(float* buffer, int num_frames, int num_channels) 
{
    if (sid_playing)
        cRSID_generateFloat(sidplayer_c64, buffer, (unsigned short)(num_frames * num_channels * sizeof(float)));
    else
        memset(buffer, 0, num_frames * num_channels * sizeof(float));
}

static void print_help() 
{
	printf("\nUsage: sidplayer hq=<true/false> [song=file]\n"
		   "\n"
		   "Supported song formats:\n"
		   "- PSID\n"
		   "- RSID\n"
		   "\n");
}

int main(int argc, char *argv[]) 
{
	sargs_desc init_args;
	memset(&init_args, 0, sizeof(sargs_desc));
	init_args.argc = argc;
	init_args.argv = argv;
	sargs_setup(&init_args);

	if (sargs_exists("help") || !sargs_exists("hq")) 
    {
		print_help();
		sargs_shutdown();
		exit(EXIT_SUCCESS);
	}

    // setup sokol_audio (default sample rate is 44100Hz)
	saudio_desc init_saudio;
	memset(&init_saudio, 0, sizeof(saudio_desc));
	init_saudio.num_channels = 2;
	init_saudio.stream_cb = stream_cb;
	init_saudio.logger.func = slog_func;
	saudio_setup(&init_saudio);
    if (!saudio_isvalid())
    {
        saudio_shutdown();
		printf("sidplayer: Error initializing audio backend\n");
		sargs_shutdown();
		exit(EXIT_FAILURE);
    }
    if (saudio_channels() != 2)
    {
        saudio_shutdown();
		printf("sidplayer: Audio backend does not support stereo output\n");
		sargs_shutdown();
		exit(EXIT_FAILURE);
    }
   
    sidplayer_c64 = cRSID_init(saudio_sample_rate(), sargs_boolean("hq"));
    if (sidplayer_c64 == NULL)
    {
        saudio_shutdown();
		printf("sidplayer: Error initializing cRSID\n");
		sargs_shutdown();
		exit(EXIT_FAILURE);
    }

	const char *song = sargs_value("song");

    cRSID_SIDheader *loaded_track = NULL;

	if (*song != '\0')
        loaded_track = cRSID_processSIDfile(sidplayer_c64, song);
    else
        loaded_track = cRSID_processSIDbuffer(sidplayer_c64, edge_of_disgrace, sizeof(edge_of_disgrace));
        
    if (loaded_track != NULL)
    {
        cRSID_initSIDtune(sidplayer_c64, loaded_track, 0);
        sid_playing = true;
    }
    else
    {
        printf("sidplayer: Error starting playback\n");
        saudio_shutdown();
        sargs_shutdown();
        exit(EXIT_FAILURE);
    }

	printf("Playing %s....press enter to exit\n", *song != '\0' ? song : "Edge of Disgrace.sid");
	fflush(stdout);
	getchar();

	sid_playing = false;

	saudio_shutdown();
	sargs_shutdown();

    // hard-reset, frees memory that was allocated if an external song was loaded
    cRSID_reset(sidplayer_c64);

	return EXIT_SUCCESS;
}