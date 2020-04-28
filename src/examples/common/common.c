#include "common.h"
#include "state-internals.h"
#include "SDL.h"
#include "state.h"

static void cyex_empty_tick(struct cyex_state * s, uint32_t dt) { }
static void cyex_empty_render(struct cyex_state * s) { }

void cyex_start(struct cyex_state * state) {
  SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_TIMER);

  struct cyex_state_internals * internals = SDL_malloc(sizeof(*internals));
  internals->window = SDL_CreateWindow(
      state->window.title,
      (int) (state->window.position.x < 0 ? SDL_WINDOWPOS_CENTERED : state->window.position.x),
      (int) (state->window.position.y < 0 ? SDL_WINDOWPOS_CENTERED : state->window.position.y),
      (int) state->window.size.width,
      (int) state->window.size.height,
      SDL_WINDOW_RESIZABLE
  );
  internals->renderer = SDL_CreateRenderer(internals->window, -1, SDL_RENDERER_ACCELERATED);
  internals->quit_requested = SDL_FALSE;
  state->internals = internals;

  if (!state->tick) state->tick = cyex_empty_tick;
  if (!state->render) state->render = cyex_empty_render;

  uint32_t accumulator = 0.0, now = SDL_GetTicks();
  const uint32_t target = 16;

  while (!internals->quit_requested) {
    uint32_t new_time = SDL_GetTicks();
    uint32_t dt = new_time - now;
    now = new_time;
    accumulator += dt;

    SDL_PumpEvents();
    SDL_Event event;

    /* get all window resize events */
    while (SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_WINDOWEVENT, SDL_WINDOWEVENT) > 0) {
      if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
        state->window.size.width = (float) event.window.data1;
        state->window.size.height = (float) event.window.data2;
      }
    }

    while (accumulator >= target) {
      state->tick(state, target);
      accumulator -= target;
    }

    SDL_RenderClear(internals->renderer);
    state->render(state);
    SDL_RenderPresent(internals->renderer);
    if (SDL_QuitRequested()) internals->quit_requested = SDL_TRUE;
    SDL_Delay(1); /* just to release CPU pressure a bit */
  }

}

void cyex_quit(struct cyex_state * state) {
  struct cyex_state_internals * internals = state->internals;
  SDL_DestroyRenderer(internals->renderer);
  SDL_DestroyWindow(internals->window);
  SDL_free(internals);
  SDL_Quit();
  state->internals = NULL;
}

void cyex_delay(float seconds) {
  uint32_t milliseconds = (int)(seconds * 1000);
  SDL_Delay(milliseconds);
}