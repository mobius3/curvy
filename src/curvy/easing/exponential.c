#include "curvy/easing/exponential.h"
#include <math.h>

float cy_exponential(float p, float start, float end) {
  p *= 2;
  if (p < 1) {
    return (((end - start) / 2) * powf(2, 10 * (p - 1)) + start);
  }
  --p;
  return (((end - start) / 2) * (-powf(2, -10 * p) + 2) + start);
}

float cy_exponential_in(float p, float start, float end) {
  return ((end - start) * powf(2, 10 * (p - 1)) + start);
}

float cy_exponential_out(float p, float start, float end) {
  return ((end - start) * (-powf(2, -10 * p) + 1) + start);
}