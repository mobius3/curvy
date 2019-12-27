#ifndef CURVY_TWEEN_PRIVATE_H
#define CURVY_TWEEN_PRIVATE_H

#include "curvy/tween.h"
#include "curvy/control-point.h"

#if __cplusplus
extern "C" {
#endif

void cy_tween_render(struct cy_tween * tween, float duration);
struct cy_control_point * cy_tween_get_next_cp(struct cy_tween * tween);
void cy_tween_start(struct cy_tween * tween);

#if __cplusplus
}
#endif

#endif