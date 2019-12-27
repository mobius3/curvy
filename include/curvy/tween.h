#ifndef CURVY_TWEEN_H
#define CURVY_TWEEN_H

#include "curvy/curvy-export.h"
#include "curvy/control-point.h"
#include "curvy/boolean.h"
#include <stdlib.h>

#if __cplusplus
extern "C" {
#endif

#ifndef CURVY_MAX_CONTROL_POINTS
#define CURVY_MAX_CONTROL_POINTS 32
#endif

struct cy_tween;
typedef float (*cy_tween_callback)(struct cy_tween * tween, float value);

struct cy_tween {
  float from;
  uint16_t to_count;


  cy_tween_callback on_step;
  cy_tween_callback on_seek;

  float value;
  float duration;
  float current_duration;
  uint8_t initialized;

  struct cy_control_point to[CURVY_MAX_CONTROL_POINTS];
};

extern CURVY_EXPORT struct cy_tween * cy_from(struct cy_tween * tween, float value);
extern CURVY_EXPORT struct cy_tween * cy_to(struct cy_tween * tween, float value, cy_easing_fn via, float during);

extern CURVY_EXPORT float cy_seek(struct cy_tween * tween, float seek_duration);
extern CURVY_EXPORT float cy_step(struct cy_tween * tween, float step_duration);
extern CURVY_EXPORT float cy_jump(struct cy_tween * tween, uint16_t jump_index);
extern CURVY_EXPORT enum cy_boolean cy_finished(struct cy_tween const * tween);

#if __cplusplus
}
#endif

#endif