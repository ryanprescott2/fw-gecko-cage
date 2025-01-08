# change APP_NAME
set(APP_NAME gecko_cage)

list(APPEND ${APP_NAME}_files main.cpp)

# pick which boards the application should build for
# list(APPEND board_list hydra hydrav2)

unspun_create_app("${APP_NAME}" "${${APP_NAME}_files}" "${${APP_NAME}_deps}" "${board_list}")

foreach(board ${board_list})
  target_compile_definitions(${APP_NAME}.elf
      PUBLIC
      # Change APPLICATION_TYPE value
      APPLICATION_TYPE=1
  )
endforeach()