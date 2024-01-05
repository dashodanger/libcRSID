# libcRSID
This is an adaptation of the library version of cRSID for embedding in game engines or other applications. Changes have been made for easier compilation in C/C++ environments and with varying compilers (tested with MSVC, GCC, and Clang across different operating systems). SDL and filesystem references have been removed; the library is intended to receive an in-memory SID track and produce samples on demand.

# Usage

- Initialize a `cRSID_C64instance` with the `cRSID_Init` function, passing the desired frequency/sampling rate as a parameter.
- Initialize a `cRSID_SIDheader` with the `cRSID_processSIDfile` function, passing the previously created `cRSID_C64instance` as well as a pointer to a memory buffer containing the SID track and its length as parameters.
- Prepare the SID track for playback with the `cRSID_processSIDfile` function, passing the `cRSID_C64instance`, `cRSID_SIDheader`, and the number of the subtune to play (or 0 if not applicable). This will not generate any audio yet.
- In an appropriate place in your program, call the `cRSID_generateSound` function, passing the `cRSID_C64instance`, a pointer to an initialized buffer to store the generated samples and its legnth as parameters. Generated samples will be in the form of pairs of signed 16-bit integers.
