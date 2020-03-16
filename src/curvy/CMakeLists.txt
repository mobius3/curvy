include(GNUInstallDirs)
include(GenerateExportHeader)

set (I ../../include)

set(CURVY_PUBLIC_HEADERS
  ${I}/curvy/boolean.h
  ${I}/curvy/curvy.h
  ${I}/curvy/tween.h
  ${I}/curvy/control-point.h
  ${CMAKE_CURRENT_BINARY_DIR}/curvy/curvy-export.h
)

add_library(
  curvy
  tween.c
  tween-private.c
  tween-private.h
  ${CURVY_PUBLIC_HEADERS}
)

generate_export_header(curvy BASE_NAME curvy EXPORT_FILE_NAME curvy/curvy-export.h)

add_library(curvy::curvy ALIAS curvy)

set_target_properties(curvy PROPERTIES
  C_STANDARD 99
  VERSION ${curvy_VERSION}
  SOVERSION ${curvy_VERSION_MAJOR}
  PUBLIC_HEADER "${CURVY_PUBLIC_HEADERS}"
  OUTPUT_NAME "curvy"
)

target_include_directories(curvy PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<INSTALL_INTERFACE:include>
)

target_compile_options(curvy PRIVATE
  $<$<OR:$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:GNU>>:-Wall -Wextra -pedantic -fvisibility=hidden -Werror>
  $<$<C_COMPILER_ID:MSVC>:/W3 /WX /wd4820 /wd4668 /wd4204>
)

target_link_libraries(curvy PUBLIC curvy::easing)

install(TARGETS curvy
  EXPORT curvy-targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  COMPONENT "Curvy Runtime"
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  COMPONENT "Curvy Runtime"
  NAMELINK_COMPONENT "Curvy Development"
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  COMPONENT "Curvy Development"
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/curvy
  COMPONENT "Curvy Development"
)

if (NOT MSVC)
  target_link_libraries(curvy PUBLIC "-lm")
endif ()

