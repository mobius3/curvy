#include "curvy/easing/circular.h"
#include <math.h>

float cy_circular(float p, float start, float end) {

  p *= 2;
  if (p < 1) {
    return (float)((-(end - start) / 2) * (sqrtf(1 - p * p) - 1) + start);
  }

  p -= 2;
  return (float)(((end - start) / 2) * (sqrtf(1 - p * p) + 1) + start);
}

float cy_circular_in(float p, float start, float end) {
  return (-(end - start) * (sqrtf(1 - p * p) - 1) + start);
}

float cy_circular_out(float p, float start, float end) {
  --p;
  return ((end - start) * (sqrtf(1 - p * p)) + start);
}