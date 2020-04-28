#ifndef CURVY_EXAMPLES_COMMON_STATE_H
#define CURVY_EXAMPLES_COMMON_STATE_H

#include <stdint.h>
#include "size.h"
#include "point.h"

#if __cplusplus
extern "C" {
#endif

struct cyex_state_internals;
struct cyex_state;

typedef void (*tick_fn)(struct cyex_state * state, uint32_t dt);
typedef void (*render_fn)(struct cyex_state * state);

struct cyex_state {
  struct {
    struct cyex_size size;
    struct cyex_point position;
    char const * title;
  } window;

  tick_fn tick;
  render_fn render;

  void * data;

  struct cyex_state_internals * internals;
};

#if (WIN32)
#define main SDL_main
#endif

#if __cplusplus
};
#endif

#endif /* CURVY_EXAMPLES_COMMON_STATE_H */