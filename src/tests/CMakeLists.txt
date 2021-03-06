macro(cy_test)
  # multiple sources
  if (${ARGC} GREATER 1)
    set(test_name "${ARGV0}")
    set(src ${ARGN})
    list(REMOVE_AT src 0)
  else()
    set(test_name "test-${ARGV0}")
    set(src "${ARGV0}.c")
  endif()
  message(STATUS "Adding test ${test_name} (${src})")
  add_executable(${test_name} ${src})
  target_link_libraries(${test_name} curvy criterion)
  add_test(NAME ${test_name} COMMAND ${test_name})
endmacro()

find_package(Criterion QUIET)
if (CRITERION_FOUND)
  cy_test(test-tween tween/tween.c)
  cy_test(test-tween-from tween/from.c)
  cy_test(test-tween-to tween/to.c)
  cy_test(test-tween-step tween/step.c)
  cy_test(test-tween-seek tween/seek.c)
  cy_test(test-tween-jump tween/jump.c)

  cy_test(test-all-easings easing/all-easings.c easing/test-easing-fn.c easing/test-easing-fn.h)
else()
  message(STATUS "Criterion was not found. Tests disabled.")
endif()