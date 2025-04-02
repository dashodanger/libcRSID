##########################################
# sidplayer
##########################################

cmake_minimum_required(VERSION 3.25)

project(
  sidplayer
  LANGUAGES C
)

add_executable(
  sidplayer
  sidplayer-sapp.c
)

# sokol_app/sokol_audio linked libraries
if (WIN32 OR MINGW)
  target_compile_definitions (sidplayer PUBLIC SOKOL_D3D11)
  target_link_libraries(sidplayer d3d11 winmm kernel32)
elseif (CMAKE_HOST_LINUX)
  target_compile_definitions (sidplayer PUBLIC SOKOL_GLCORE33)
  target_link_libraries(sidplayer asound X11 Xi Xcursor GL dl pthread m)
endif()