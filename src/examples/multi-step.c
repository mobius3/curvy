#include <curvy/tween.h>
#include <curvy/easing/linear.h>
#include <rect.h>
#include <curvy/easing/back.h>
#include <curvy/easing/elastic.h>
#include "common.h"

void tick(struct cyex_state * state, uint32_t dt);
void render(struct cyex_state * state);

struct example_data {
  struct cy_tween size_tween;
};

int main(int argc, char const * const * argv) {
  struct example_data data = {
      .size_tween = {
          .from = 50.0f,
          .to = {
              { 100.0f, .during = 1000, .via = cy_back_out },
              { 50.0f, .during = 1000, .via = cy_back_in }
          }
      }
  };

  struct cyex_state state = {
      .window = {
          .size = { 200.0f, 200.0f },
          .position = { -1, -1 },
          .title = "Curvy multi-step example"
      },
      .data = &data,
      .tick = tick,
      .render = render
  };

  cyex_start(&state);
  cyex_quit(&state);
  return 0;
}

void tick(struct cyex_state * state, uint32_t dt) {
  struct example_data * data = state->data;
  cy_step(&data->size_tween, dt);
}

void render(struct cyex_state * state) {
  struct example_data * data = state->data;
  struct cyex_rect rect = {
      .center = {0, 0},
      .size = {
          .width = data->size_tween.value,
          .height = data->size_tween.value
      }
  };

  cyex_draw_rect(state, &rect, cyex_make_color(1, 0, 0, 0), cyex_make_color(0, 1, 0, 0));
}