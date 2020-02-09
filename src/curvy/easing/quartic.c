#include "curvy/easing/quartic.h"

float cy_quartic(float p, float start, float end) {
  p *= 2;
  if (p < 1) {
    return (((end - start) / 2) * (p * p * p * p) +
                          start);
  }
  p -= 2;
  return ((-(end - start) / 2) * (p * p * p * p - 2) +
                        start);
}

float cy_quartic_in(float p, float start, float end) {
  return ((end - start) * p * p * p * p + start);
}

float cy_quartic_out(float p, float start, float end) {
  --p;
  return ( -(end - start) * (p * p * p * p - 1) + start);
}