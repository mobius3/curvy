#include <criterion/criterion.h>
#include "curvy/tween.h"

static float mock_easing_linear(float p, float start, float end) {
  return (end-start) * p + start;
}

/* test cy_from */
Test(tween, from_initializes_tween) {
  struct cy_tween tween = {};
  cy_from(&tween, 0);
  cr_assert(tween.initialized == CY_TRUE);
}

Test(tween, from_sets_from_value) {
  struct cy_tween tween = {};
  cy_from(&tween, 100.0f);
  cr_assert(tween.from == 100.0f);
}

Test(tween, from_maintains_current_duration) {
  struct cy_tween tween = {
      .from = 0,
      .to = {{ .value = 1, .during = 100 }}
  };
  tween.current_duration = 50;

  cy_from(&tween, 0.5f);
  cr_assert(tween.current_duration == 50);
}

Test(tween, from_corrects_value) {
  struct cy_tween tween = {};
  cy_from(&tween, 0);
  cy_to(&tween, 100, mock_easing_linear, 100);
  cr_assert_eq(tween.value, 0.0f);

  cy_from(&tween, -100);
  cr_assert_eq(tween.value, -100);
}

Test(tween, from_keeps_finished_state) {
  struct cy_tween tween = {
      .from = 0,
      .to = {
          { .value = 1, .during = 100 }
      }
  };

  cy_seek(&tween, 0);
  cr_expect_eq(cy_finished(&tween), CY_FALSE);

  cy_from(&tween, -100);
  cr_assert_eq(cy_finished(&tween), CY_FALSE);

  cy_seek(&tween, 100.0f);
  cr_expect_eq(cy_finished(&tween), CY_TRUE);

  cy_from(&tween, 0);
  cr_assert_eq(cy_finished(&tween), CY_TRUE);
}