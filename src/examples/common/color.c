#include "color.h"

struct cyex_color cyex_make_color(float r, float g, float b, float a) {
  struct cyex_color c = {r, g, b, a};
  return c;
}