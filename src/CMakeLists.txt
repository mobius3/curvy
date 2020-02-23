list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake-modules)

add_subdirectory(curvy/easing)
add_subdirectory(curvy)

if (CURVY_BUILD_DOCS)
  add_subdirectory(docs)
endif()

if (CURVY_BUILD_TESTS)
  add_subdirectory(tests)
endif()