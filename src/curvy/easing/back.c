#include "curvy/easing/back.h"

float cy_back(float p, float start, float end) {
  float s = 1.70158f;
  float t = p;
  float b = start;
  float c = end - start;
  float d = 1;
  s *= (1.525f);
  if ((t /= d / 2) < 1) return (float)(c / 2 * (t * t * (((s) + 1) * t - s)) + b);
  float postFix = t -= 2;
  return (float)(c / 2 * ((postFix) * t * (((s) + 1) * t + s) + 2) + b);
}

float cy_back_in(float p, float start, float end) {
  float s = 1.70158f;
  float postFix = p;
  return (float)((end - start) * (postFix) * p * ((s + 1) * p - s) + start);
}

float cy_back_out(float p, float start, float end) {
  float s = 1.70158f;
  p -= 1;
  return (float)((end - start) * ((p) * p * ((s + 1) * p + s) + 1) + start);
}