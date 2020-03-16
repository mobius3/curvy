#include "curvy/tween.h"

#include "curvy/control-point.h"
#include "tween-private.h"

#include <stdint.h>

struct cy_tween * cy_from(struct cy_tween * tween, float value) {
  tween->from = value;
  cy_seek(tween, tween->current_duration);
  return tween;
}

struct cy_tween * cy_to(struct cy_tween * tween, float value, cy_easing_fn via, float during) {
  struct cy_control_point * cp = cy_tween_get_next_cp(tween);
  cp->value = value;
  cp->via = via;
  cp->during = during;
  tween->duration += during;
  cp->stacked_duration = tween->duration;
  cy_seek(tween, tween->current_duration);
  return tween;
}

float cy_step(struct cy_tween * tween, float duration) {
  if (!tween->initialized) cy_tween_start(tween);
  cy_tween_render(tween, tween->current_duration + duration);
  return tween->value;
}

float cy_seek(struct cy_tween * tween, float duration) {
  if (!tween->initialized) cy_tween_start(tween);
  cy_tween_render(tween, duration);
  return tween->value;
}

float cy_jump(struct cy_tween * tween, uint16_t point_index) {
  if (!tween->initialized) cy_tween_start(tween);
  if (!tween->to_count || point_index == 0) return cy_seek(tween, 0);
  if (point_index >= tween->to_count +1) point_index = tween->to_count;
  int to_index = point_index - 1; /* `from` value is considered point 0 */
  return cy_seek(tween, tween->to[to_index].stacked_duration);
}

enum cy_boolean cy_finished(struct cy_tween const * tween) {
  if (!tween->initialized) return CY_FALSE;
  return tween->current_duration >= tween->duration;
}