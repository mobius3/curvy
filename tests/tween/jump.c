#include <criterion/criterion.h>
#include "curvy/tween.h"

static float mock_easing_linear(float p, float start, float end) {
  return (end-start) * p + start;
}

Test(tween, jump_initializes_tween) {
  struct cy_tween tween = {};
  cy_seek(&tween, 0);
  cr_assert(tween.initialized == CY_TRUE);
}

Test(tween, jump_changes_duration) {
  struct cy_tween tween = {
      .from = 0,
      .to = {
          {.value = 1, .during = 100}
      },
  };

  cy_jump(&tween, 1);
  cr_assert(tween.current_duration == 100);

  cy_jump(&tween, 0);
  cr_assert(tween.current_duration == 0);
}

Test(tween, jump_correctly_interpolates_through_easing_fn) {
  struct cy_tween tween = {
      .from = 0,
      .to = {
          { 100, .via = mock_easing_linear, .during = 100 },
          { 200, .via = mock_easing_linear, .during = 100 },
      }
  };
  cy_jump(&tween, 1);
  cr_assert_eq(tween.value, 100.0f);

  cy_jump(&tween, 2);
  cr_assert_eq(tween.value, 200.0f);
}
