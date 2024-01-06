##########################################
# sidplayer
##########################################

project(
  sidplayer
  LANGUAGES C
)

add_executable(
  sidplayer
  libcRSID.c
  example/sidplayer-sapp.c
)

add_custom_command(
  TARGET sidplayer
  POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy "$<TARGET_FILE:sidplayer>"
          "${CMAKE_CURRENT_LIST_DIR}"
)