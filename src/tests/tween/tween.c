#include <criterion/criterion.h>
#include "curvy/tween.h"

/* sanity check for struct initialization */
Test(tween, initialized_automatically_set_to_false) {
  struct cy_tween tween = {};
  cr_assert(tween.initialized == CY_FALSE);
}

Test(tween, finished_is_false_for_empty_tween) {
  struct cy_tween tween = {};
  cr_assert_eq(cy_finished(&tween), CY_FALSE);
}