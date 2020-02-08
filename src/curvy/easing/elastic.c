#include <math.h>
#include "curvy/easing/elastic.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288
#endif

float cy_elastic(float p, float start, float end) {
  if (p <= 0.00001f) return start;
  if (p >= 0.999f) return end;
  p *= 2;
  float z = (.3f * 1.5f);
  float a = end - start;
  float s = z / 4;
  float postFix;

  if (p < 1) {
    postFix = a * powf(2, 10 * (p -= 1)); // postIncrement is evil
    return (-0.5f * (postFix * (float)(sinf((p - s)) * (2 * (M_PI)) / z)) + start);
  }
  postFix = a * powf(2, -10 * (p -= 1)); // postIncrement is evil
  return (postFix * (float)(sinf((p - s)) * (2 * (M_PI)) / z) * .5f + end);}

float cy_elastic_in(float p, float start, float end) {
  if (p <= 0.00001f) return start;
  if (p >= 0.999f) return end;
  float z = .3f;
  float a = end - start;
  float s = p / 4;
  float postFix =
      a * powf(2, 10 * (p -= 1)); // this is a fix, again, with post-increment operators
  return (-(postFix * sinf((p - s) * (2 * (float)(M_PI)) / z)) + start);
}

float cy_elastic_out(float p, float start, float end) {
  if (p <= 0.00001f) return start;
  if (p >= 0.999f) return end;
  float z = .3f;
  float a = end - start;
  float s = z / 4;
  return (a * powf(2, -10 * p) * sinf((p - s) * (2 * (float)(M_PI)) / z) + end);
}