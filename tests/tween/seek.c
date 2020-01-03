#include <criterion/criterion.h>
#include "curvy/tween.h"

static float mock_easing_linear(float p, float start, float end) {
  return (end-start) * p + start;
}

Test(tween, seek_changes_duration) {
  struct cy_tween tween = {
      .from = 0,
      .to = {{.value = 1, .during = 100}}
  };
  cr_expect(tween.initialized == CY_FALSE);

  cy_seek(&tween, 50);
  cr_assert(tween.current_duration == 50);
}