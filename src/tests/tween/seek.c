#include <criterion/criterion.h>
#include "curvy/tween.h"

static float mock_easing_linear(float p, float start, float end) {
  return (end-start) * p + start;
}

Test(tween, seek_initializes_tween) {
  struct cy_tween tween = {};
  cy_seek(&tween, 1.0f);
  cr_assert(tween.initialized == CY_TRUE);
}

Test(tween, seek_changes_duration) {
  struct cy_tween tween = {
      .from = 0,
      .to = {{.value = 1, .during = 100}}
  };

  cy_seek(&tween, 50);
  cr_assert(tween.current_duration == 50);
}

Test(tween, seek_navigates_control_points) {
  /* we know linear to be well behaved and what to expect from it */
  struct cy_tween tween = {
      .from = 0,
      .to = {
          { 1, .via = mock_easing_linear, .during = 100 },
          { 2, .via = mock_easing_linear, .during = 100 }
      }
  };
  cy_seek(&tween, 100.0f);
  cr_assert(tween.value == tween.to[0].value);

  cy_seek(&tween, 100.001f);
  cr_assert(tween.value > tween.to[0].value);
  cr_assert(tween.value < tween.to[1].value);

  cy_seek(&tween, 200.0f);
  cr_assert(tween.value == tween.to[1].value);
}

Test(tween, seek_correctly_interpolates_through_easing_fn) {
  struct cy_tween tween = {
      .from = 0,
      .to = {
          { 100, .via = mock_easing_linear, .during = 100 }
      }
  };
  cy_seek(&tween, 50);
  cr_assert_eq(tween.value, 50.0f);
}