#include "size.h"

struct cyex_size cyex_make_size(float width, float height) {
  struct cyex_size r = {width, height};
  return r;
}