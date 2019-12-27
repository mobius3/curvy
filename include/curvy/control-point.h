#ifndef CURVY_CONTROL_POINT_H
#define CURVY_CONTROL_POINT_H

#if __cplusplus
extern "C" {
#endif

typedef float (*cy_easing_fn)(float p, float start, float end);

struct cy_control_point {
  float value;
  cy_easing_fn via;
  float during;
  float stacked_duration;
};

#if __cplusplus
};
#endif

#endif