#include <criterion/criterion.h>
#include "curvy/tween.h"

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
