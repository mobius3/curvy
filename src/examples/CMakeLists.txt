cmake_policy(SET CMP0074 NEW)
find_package(SDL2 QUIET)
macro(cy_example)
  # multiple sources
  if (${ARGC} GREATER 1)
    set(example_name "${ARGV0}")
    set(src ${ARGN})
    list(REMOVE_AT src 0)
  else()
    set(example_name "example-${ARGV0}")
    set(src "${ARGV0}.c")
  endif()
  message(STATUS "Adding example ${example_name} (${src}) -> ${CMAKE_BINARY_DIR}/examples/${example_name}")
  add_executable(${example_name} ${src})
  if (WIN32)
    set_property(TARGET ${example_name} PROPERTY WIN32_EXECUTABLE 1)
  endif()
  add_custom_command(TARGET ${example_name}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${SDL2_DLL} $<TARGET_FILE_DIR:${example_name}>
  )
  target_link_libraries(${example_name} PRIVATE curvy examples-common)
endmacro()


if (SDL2_FOUND)
  add_subdirectory(common)
  cy_example(multi-step multi-step.c)

  # SDL2_DLL is set by FindSDL2.cmake
  message(STATUS "CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}")
else()
  message(STATUS "SDL2 was not found. Examples will not be built.")
endif()