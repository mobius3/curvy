#include <criterion/criterion.h>
#include "curvy/tween.h"

Test(tween, jump_initializes_tween) {
  struct cy_tween tween = {};
  cr_expect(tween.initialized == CY_FALSE);

  cy_seek(&tween, 0);
  cr_assert(tween.initialized == CY_TRUE);
}