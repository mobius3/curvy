#include "test-easing-fn.h"
#include "criterion/criterion.h"

enum cy_boolean test_easing_fn(cy_easing_fn ease, float start, float end, float const at[], float const expected[], size_t values_count) {
  for (size_t i = 0; i < values_count; ++i) {
    float v = ease(at[i], start, end);
    cr_assert(v == expected[i], "i = %lu, at[%lu] = %f, expected[%lu] = %f, actual = %f", i, i, at[i], i, expected[i], v);
  }
  return CY_TRUE;
}