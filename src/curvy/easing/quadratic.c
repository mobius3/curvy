#include "curvy/easing/quadratic.h"

float cy_quadratic(float p, float start, float end) {
  p *= 2;
  if (p < 1) {
    return (((end - start) / 2) * p * p + start);
  }

  --p;
  return ((-(end - start) / 2) * (p * (p - 2) - 1) + start);
}

float cy_quadratic_in(float p, float start, float end) {
  return ((end - start) * p * p + start);
}

float cy_quadratic_out(float p, float start, float end) {
  return ((-(end - start)) * p * (p - 2) + start);
}