#include "curvy/easing/bounce.h"

float cy_bounce(float p, float start, float end) {
  if (p < 0.5f) return (float)(cy_bounce_in(p * 2, 0, end) * .5f + start);
  else return (float)(cy_bounce_out((p * 2 - 1), 0, end) * .5f + (end - start) * .5f + start);
}

float cy_bounce_in(float p, float start, float end) {
  return (end - start) - cy_bounce_out((1 - p), 0, end) + start;
}

float cy_bounce_out(float p, float start, float end) {
  float c = end - start;
  if (p < (1 / 2.75f)) {
    return (float) (c * (7.5625f * p * p) + start);
  } else if (p < (2.0f / 2.75f)) {
    float postFix = p -= (1.5f / 2.75f);
    return (float) (c * (7.5625f * (postFix) * p + .75f) + start);
  } else if (p < (2.5f / 2.75f)) {
    float postFix = p -= (2.25f / 2.75f);
    return (float) (c * (7.5625f * (postFix) * p + .9375f) + start);
  } else {
    float postFix = p -= (2.625f / 2.75f);
    return (float) (c * (7.5625f * (postFix) * p + .984375f) + start);
  }
}