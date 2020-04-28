#ifndef CURVY_EXAMPLES_COMMON_STATE_INTERNALS_H
#define CURVY_EXAMPLES_COMMON_STATE_INTERNALS_H

#include <SDL_config.h>
#include <SDL_quit.h>

#if __cplusplus
extern "C" {
#endif

typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;

struct cyex_state_internals {
  SDL_Window * window;
  SDL_Renderer * renderer;
  SDL_bool quit_requested;
};

#if __cplusplus
};
#endif

#endif /* CURVY_EXAMPLES_COMMON_STATE_INTERNALS_H */