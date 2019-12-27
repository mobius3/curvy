include(GNUInstallDirs)
include(GenerateExportHeader)

set (I ../../../include)

set(CURVY_EASING_PUBLIC_HEADERS
  ${I}/curvy/easing/back.h
  ${I}/curvy/easing/bounce.h
  ${I}/curvy/easing/circular.h
  ${I}/curvy/easing/cubic.h
  ${I}/curvy/easing/elastic.h
  ${I}/curvy/easing/exponential.h
  ${I}/curvy/easing/linear.h
  ${I}/curvy/easing/quadratic.h
  ${I}/curvy/easing/quartic.h
  ${I}/curvy/easing/quintic.h
  ${I}/curvy/easing/sinusoidal.h
  ${CMAKE_CURRENT_BINARY_DIR}/curvy/easing/curvy-easing-export.h
)

add_library(
  easing STATIC
  back.c
  bounce.c
  circular.c
  cubic.c
  elastic.c
  exponential.c
  linear.c
  quadratic.c
  quartic.c
  quintic.c
  sinusoidal.c
  ${CURVY_EASING_PUBLIC_HEADERS}
)

generate_export_header(easing BASE_NAME curvy-easing EXPORT_FILE_NAME curvy/easing/curvy-easing-export.h)

add_library(curvy::easing ALIAS easing)

set_target_properties(easing PROPERTIES
  C_STANDARD 99
  VERSION ${curvy_VERSION}
  SOVERSION ${curvy_VERSION_MAJOR}
  PUBLIC_HEADER "${CURVY_EASING_PUBLIC_HEADERS}"
  OUTPUT_NAME "curvy-easing"
)

target_include_directories(easing PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../../include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<INSTALL_INTERFACE:include>
)

target_compile_options(easing PRIVATE
  $<$<OR:$<C_COMPILER_ID:Clang>,$<C_COMPILER_ID:GNU>>:-Wall -Wextra -pedantic -fvisibility=hidden -Werror>
  $<$<C_COMPILER_ID:MSVC>:/W3 /WX /wd4820 /wd4668 /wd4204>)


install(TARGETS easing
  EXPORT curvy-targets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  COMPONENT "Curvy Easing Runtime"
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  COMPONENT "Curvy Easing Runtime"
  NAMELINK_COMPONENT "Curvy Easing Development"
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  COMPONENT "Curvy Easing Development"
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/curvy/easing
  COMPONENT "Curvy Easing Development"
)

if (NOT MSVC)
  target_link_libraries(easing PUBLIC "-lm")
endif ()

