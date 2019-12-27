enable_testing()
cmake_minimum_required(VERSION 3.0)
project(curvy LANGUAGES C VERSION 1.0.0)
set(CMAKE_C_STANDARD 99)

# Respect VISIBILITY_PRESET
cmake_policy(SET CMP0063 NEW)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
option(CURVY_ENABLE_TESTING "Build and run test code in tests/" ON)

if (NOT APPLE)
  set(CMAKE_INSTALL_RPATH $ORIGIN)
endif()

add_subdirectory(src)

if (CURVY_ENABLE_TESTING)
  add_subdirectory(tests)
endif()

include(cmake/setup-exports.cmake)
include(cmake/curvy-cpack.cmake)

