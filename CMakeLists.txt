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
  libcRSID.c
  example/sidplayer-sapp.c
)

# sokol_app/sokol_audio linked libraries
if (CMAKE_HOST_LINUX)
  target_link_libraries(sidplayer asound X11 Xi Xcursor GL dl pthread m)
endif()

add_custom_command(
  TARGET sidplayer
  POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:sidplayer>"
          "${CMAKE_CURRENT_LIST_DIR}"
)