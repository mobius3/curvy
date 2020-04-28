#ifndef CURVY_EXAMPLES_COMMON_H
#define CURVY_EXAMPLES_COMMON_H

#if __cplusplus
extern "C" {
#endif

#include "state.h"
#include "draw.h"

void cyex_start(struct cyex_state * state);
void cyex_quit(struct cyex_state * state);
void cyex_delay(float seconds);

#if (WIN32)
#define main SDL_main
#endif

#if __cplusplus
};
#endif

#endif