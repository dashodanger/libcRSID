# libcRSID
This is an adaptation of the library version of cRSID for embedding in game engines or other applications. Changes have been made for easier compilation in C/C++ environments and with varying compilers (tested with MSVC, GCC, and Clang across different operating systems). SDL and filesystem references have been removed; the library is intended to receive an in-memory SID track and produce samples on demand.

# Compilation
`libcRSID.c` is the only file that needs to be added to your Makefile/CMakeLists/etc. Include `libcRSID.h` in the source file that you are using to handle SID playback.

To compile a test program, please use the CMakeLists file in this directory. It will build a small program that displays a window and replays an embedded SID file.
- The test program uses the Sokol libraries which are zlib-licensed and is based on the mod player example from sokol-samples, which is MIT licensed. Neither of these licenses affect libcRSID when compiled on its own.

# Usage
- Initialize a `cRSID_C64instance` pointer with the `cRSID_Init` function, passing the desired frequency/sampling rate as a parameter.
- Initialize a `cRSID_SIDheader` pointer with the `cRSID_processSIDfile` function, passing the previously created `cRSID_C64instance` as well as a pointer to a memory buffer containing the SID track and its length as parameters.
  - NOTE: The `cRSID_SIDheader` will use the same pointer as the memory buffer you passed to it here. It is NOT safe to free this buffer until you are completely done with the track!
- Prepare the SID track for playback with the `cRSID_initSIDtune` function, passing the `cRSID_C64instance`, `cRSID_SIDheader`, and the number of the subtune to play (or 0 if not applicable). This will not generate any audio yet.
- In an appropriate place in your program, call the `cRSID_generateSound` function, passing the `cRSID_C64instance`, a pointer to an initialized buffer to store the generated samples and its length as parameters. Generated samples will be in the form of pairs of signed 16-bit integers.
- When finished, hard-reset the SID with the `crSID_initC64` function, passing the `cRSID_C64instance` as a parameter. Do NOT try to free the memory represented by the `cRSID_C64instance` pointer after this; rather set it to NULL as with the way cRSID works under the hood this will remove a global `cRSID_C64instance` that the library relies on. Next, set the `cRSID_SIDheader` pointer to NULL and then free the memory represented by the original pointer used to instantiate it (if not planning to reuse it).
