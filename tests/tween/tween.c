#include <criterion/criterion.h>
#include "curvy/tween.h"

/* sanity check for struct initialization */
Test(tween, initialized_automatically_set_to_false) {
  struct cy_tween tween = {};
  cr_assert(tween.initialized == CY_FALSE);
}