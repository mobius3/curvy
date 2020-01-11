#include <curvy/easing/linear.h>
#include "criterion/criterion.h"
#include "test-easing-fn.h"

Test(easing, linear_easing_return_expected_values) {
  float at[] = { 0, 0.5f, 1.0f }, expected[] = { 0.0f, 0.5f, 1.0f };
  test_easing_fn(cy_linear, 0, 1, at, expected, 3);
}