#include <curvy/easing/linear.h>
#include "tween-private.h"
#include "curvy/control-point.h"

struct cy_control_point * cy_tween_get_next_cp(struct cy_tween * tween) {
  if (tween->to_count >= CURVY_MAX_CONTROL_POINTS) {
    return NULL;
  }
  tween->to_count += 1;
  return &tween->to[tween->to_count - 1];
}

uint16_t cy_tween_start_cps(struct cy_tween * tween) {
  uint16_t i = 0;
  for (i = 0; i < CURVY_MAX_CONTROL_POINTS; i++) {
    struct cy_control_point * cp = &tween->to[i];
    if (cp->via == NULL && cp->during == 0.0f && cp->value == 0 && cp->stacked_duration == 0) break;
    tween->duration += cp->during;
    cp->stacked_duration = tween->duration;
  }
  return i;
}

void cy_tween_start(struct cy_tween * tween) {
  tween->duration = 0;
  tween->current_duration = 0;
  tween->to_count = cy_tween_start_cps(tween);
  tween->initialized = 1;
}

void cy_tween_render(struct cy_tween * tween, float duration) {

  if (tween->to_count == 0) {
    tween->value = tween->from;
    tween->current_duration = 0;
    return;
  }

  if (duration > tween->duration) duration = tween->duration;
  if (duration < 0) duration = 0;

  /* finds the index of the first control point after the specified duration, effectively to_cp */
  uint16_t to_i = 0;
  for (to_i = 0; duration > tween->to[to_i].stacked_duration; ++to_i);
  struct cy_control_point const * to = &tween->to[to_i];

  /* store intermediary values */
  float from_value = to_i == 0 ? tween->from : tween->to[to_i -1].value;
  float total_duration = to->during;

  /* converts the passed duration into a value between 0 and to_cp->during, considering from_cp stacked duration values */
  float current_duration = duration - (to_i == 0 ? 0 : tween->to[to_i -1].stacked_duration);
  cy_easing_fn via = to->via;
  if (to->via == NULL) via = cy_linear;
  tween->value = via(current_duration / total_duration, from_value, to->value);
  tween->current_duration = duration;
}