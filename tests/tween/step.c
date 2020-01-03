#include <criterion/criterion.h>
#include "curvy/tween.h"

static float mock_easing_linear(float p, float start, float end) {
  return (end-start) * p + start;
}

/* test cy_step */
Test(tween, step_initializes_tween) {
  struct cy_tween tween = {};
  cy_step(&tween, 1.0f);
  cr_assert(tween.initialized == CY_TRUE);
}

Test(tween, step_increases_duration) {
  struct cy_tween tween = {
      .from = 0,
      .to = {
          { 100, .via = mock_easing_linear, .during = 100 }
      }
  };
  cy_step(&tween, 1.0f);
  cr_assert(tween.current_duration == 1.0f);
}

Test(tween, step_navigates_control_points) {
  /* we know linear to be well behaved and what to expect from it */
  struct cy_tween tween = {
      .from = 0,
      .to = {
          { 1, .via = mock_easing_linear, .during = 100 },
          { 2, .via = mock_easing_linear, .during = 100 }
      }
  };
  cy_step(&tween, 100.0f);
  cr_assert(tween.value == tween.to[0].value);

  cy_step(&tween, 0.001f);
  cr_assert(tween.value > tween.to[0].value);
  cr_assert(tween.value < tween.to[1].value);

  cy_step(&tween, 100.0f - 0.001f);
  cr_assert(tween.value == tween.to[1].value);
}