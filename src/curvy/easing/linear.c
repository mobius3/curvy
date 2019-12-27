#include "curvy/easing/linear.h"

float cy_linear(float p, float start, float end) {
  return (end-start) * p + start;
}