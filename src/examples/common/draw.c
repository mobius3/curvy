#include "draw.h"
#include "state.h"
#include "state-internals.h"
#include "SDL.h"
#include "rect.h"

void cyex_draw_rect(struct cyex_state * state, struct cyex_rect const * rect, struct cyex_color bg, struct cyex_color fg) {
  SDL_Renderer * renderer = state->internals->renderer;
  struct cyex_point window_center = {
      .x = state->window.size.width / 2,
      .y = state->window.size.height / 2
  };

  SDL_FRect frect = {
      .x = floorf((window_center.x + rect->center.x) - rect->size.width / 2),
      .y = floorf((window_center.y + rect->center.y) - rect->size.height / 2),
      .w = rect->size.width,
      .h = rect->size.height
  };

  uint8_t r, g, b, a;

  SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);

  SDL_SetRenderDrawColor(renderer, bg.r * 255, bg.g * 255, bg.b * 255, bg.a * 255);
  SDL_RenderFillRectF(renderer, &frect);

  SDL_SetRenderDrawColor(renderer, fg.r * 255, fg.g * 255, fg.b * 255, fg.a * 255);
  SDL_RenderDrawRectF(renderer, &frect);

  SDL_SetRenderDrawColor(renderer, r, g, b, a);
}