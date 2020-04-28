#ifndef CURVY_EXAMPLES_COMMON_RECT_H
#define CURVY_EXAMPLES_COMMON_RECT_H

#if __cplusplus
extern "C" {
#endif

#include "point.h"
#include "size.h"

struct cyex_rect {
  struct cyex_point center;
  struct cyex_size size;
};

#if __cplusplus
};
#endif

#endif