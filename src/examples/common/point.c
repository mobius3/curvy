#include "point.h"

struct cyex_point cyex_make_point(float x, float y) {
  struct cyex_point r = {x, y};
  return r;
}