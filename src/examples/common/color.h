#ifndef CURVY_EXAMPLES_COMMON_COLOR_H
#define CURVY_EXAMPLES_COMMON_COLOR_H

#if __cplusplus
extern "C" {
#endif

struct cyex_color {
  float r, g, b, a;
};

struct cyex_color cyex_make_color(float r, float g, float b, float a);

#if __cplusplus
};
#endif

#endif