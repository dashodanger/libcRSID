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

add_library(
  libcrsid
  ../libcRSID.c
)

set(SIDPLAYER_LINK_LIBRARIES libcrsid)

# sokol_app/sokol_audio linked libraries
if (CMAKE_HOST_LINUX)
  set(SIDPLAYER_LINK_LIBRARIES ${SIDPLAYER_LINK_LIBRARIES} asound X11 Xi Xcursor GL dl pthread m)
endif()

target_link_libraries(sidplayer ${SIDPLAYER_LINK_LIBRARIES})

add_custom_command(
  TARGET sidplayer
  POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:sidplayer>"
          "${CMAKE_CURRENT_LIST_DIR}"
)