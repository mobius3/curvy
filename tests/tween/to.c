#include <criterion/criterion.h>
#include "curvy/tween.h"

static float mock_easing_linear(float p, float start, float end) {
  return (end-start) * p + start;
}

/* test cy_to */
Test(tween, to_initializes_tween) {
  struct cy_tween tween = {};

  cy_to(&tween, 10, mock_easing_linear, 100);
  cr_assert(tween.initialized == CY_TRUE);
}

Test(tween, to_adds_control_point) {
  struct cy_tween tween = {};

  cy_to(&tween, 10.0f, mock_easing_linear, 100.0f);
  cr_assert(tween.to_count == 1);
  cr_assert(tween.to[0].value == 10.0f);
  cr_assert(tween.to[0].via == mock_easing_linear);
  cr_assert(tween.to[0].during == 100.0f);

  cy_to(&tween, 20.0f, mock_easing_linear, 100.0f);
  cr_assert(tween.to_count == 2);
  cr_assert(tween.to[1].value == 20.0f);
  cr_assert(tween.to[1].via == mock_easing_linear);
  cr_assert(tween.to[1].during == 100.0f);
}


Test(tween, to_correcly_calculates_total_duration) {
  struct cy_tween tween = {};

  cy_to(&tween, 10.0f, mock_easing_linear, 100.0f);
  cy_to(&tween, 0.0f, mock_easing_linear, 50.0f);
  cr_assert(tween.duration == 150.0f);
}

Test(tween, to_correcly_calculates_stacked_duration) {
  struct cy_tween tween = {};

  cy_to(&tween, 10.0f, mock_easing_linear, 100.0f);
  cy_to(&tween, 0.0f, mock_easing_linear, 50.0f);
  cr_expect(tween.duration == 150.0f);
  cr_assert(tween.to[0].stacked_duration == 100.0f);
  cr_assert(tween.to[1].stacked_duration == 150.0f);
}

Test(tween, to_maintains_current_duration) {
  struct cy_tween tween = {};
  tween.current_duration = 50;

  cy_to(&tween, 10.0f, mock_easing_linear, 100.0f);
  cr_assert(tween.current_duration == 50);
}

Test(tween, to_maintains_current_value) {
  struct cy_tween tween = {
      .from = 0
  };

  cy_to(&tween, 100, mock_easing_linear, 100);
  cr_assert_eq(tween.value, tween.from);

  cy_seek(&tween, 50);
  cy_to(&tween, 200, mock_easing_linear, 100);
  cr_assert_eq(tween.value, 50);
}

Test(tween, finished_is_false_after_to_is_called) {
  struct cy_tween tween = {
      .from = 0
  };

  cy_to(&tween, 100, mock_easing_linear, 100);
  cr_assert_eq(cy_finished(&tween), CY_FALSE);

  cy_seek(&tween, 100.0f);
  cr_expect_eq(cy_finished(&tween), CY_TRUE);

  cy_to(&tween, 100, mock_easing_linear, 100);
  cr_assert_eq(cy_finished(&tween), CY_FALSE);
}