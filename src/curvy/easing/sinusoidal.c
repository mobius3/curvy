#include "curvy/easing/sinusoidal.h"
#import <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

float cy_sinusoidal(float p, float start, float end) {
  return ((-(end - start) / 2) * (cosf(p * (float)(M_PI)) - 1) + start);
}

float cy_sinusoidal_in(float p, float start, float end) {
  return (-(end - start) * cosf(p * (float)(M_PI) / 2) + (end - start) + start);
}

float cy_sinusoidal_out(float p, float start, float end) {
  return ((end - start) * sinf(p * (float)(M_PI) / 2) + start);
}