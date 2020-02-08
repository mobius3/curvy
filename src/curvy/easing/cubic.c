#include "curvy/easing/cubic.h"

float cy_cubic(float p, float start, float end) {
  p *= 2;
  if (p < 1) {
    return ((end - start) / 2) * p * p * p + start;
  }
  p -= 2;
  return ((end - start) / 2) * (p * p * p + 2) + start;
}

float cy_cubic_in(float p, float start, float end) {
  return (end - start) * p * p * p + start;
}

float cy_cubic_out(float p, float start, float end) {
  --p;
  return (end - start) * (p * p * p + 1) + start;
}