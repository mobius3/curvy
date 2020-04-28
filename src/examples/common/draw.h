#ifndef CURVY_EXAMPLES_COMMON_DRAW_H
#define CURVY_EXAMPLES_COMMON_DRAW_H

#include "color.h"

struct cyex_state;
struct cyex_rect;

#if __cplusplus
extern "C" {
#endif

#include "point.h"
#include "size.h"

void cyex_draw_rect(struct cyex_state * state, struct cyex_rect const * rect, struct cyex_color bg, struct cyex_color fg);

#if __cplusplus
};
#endif

#endif