add_library(examples-common STATIC
  color.c
  color.h
  common.c
  common.h
  draw.c
  draw.h
  point.c
  point.h
  rect.c
  rect.h
  size.c
  size.h
  state.h
  state-internals.h
)

target_include_directories(examples-common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(examples-common PUBLIC SDL2main SDL2)

set_target_properties(examples-common PROPERTIES
  C_STANDARD 99
  PUBLIC_HEADER "${CURVY_PUBLIC_HEADERS}"
  OUTPUT_NAME "common"
)