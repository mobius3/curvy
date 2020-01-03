#include <criterion/criterion.h>
#include "curvy/tween.h"

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