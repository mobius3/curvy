#ifndef CURVY_TEST_EASING_FN_H
#define CURVY_TEST_EASING_FN_H

#include "curvy/curvy.h"

enum cy_boolean test_easing_fn(cy_easing_fn ease,
    float begin,
    float end,
    float const at[],
    float const expected[],
    size_t values_count
  );

#endif