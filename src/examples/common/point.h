#ifndef CURVY_EXAMPLES_COMMON_POINT_H
#define CURVY_EXAMPLES_COMMON_POINT_H

#if __cplusplus
extern "C" {
#endif

struct cyex_point {
  float x;
  float y;
};

struct cyex_point cyex_make_point(float x, float y);

#if __cplusplus
};
#endif

#endif