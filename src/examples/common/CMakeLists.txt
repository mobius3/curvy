add_library(examples-common STATIC)
target_sources(examples-common
  common.h
  common.c
)

set_target_properties(examples-common PROPERTIES
  C_STANDARD 99
  PUBLIC_HEADER "${CURVY_PUBLIC_HEADERS}"
  OUTPUT_NAME "common"
)