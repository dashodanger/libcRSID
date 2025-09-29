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
  sidplayer.c
)

# sokol_audio linked libraries
if (CMAKE_HOST_LINUX AND NOT MINGW)
  target_link_libraries(sidplayer asound m)
elseif (MINGW)
  set(CMAKE_EXE_LINKER_FLAGS "-static -mconsole")
  target_link_libraries(sidplayer ole32)
endif()