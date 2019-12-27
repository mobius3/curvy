#ifndef CURVY_EASING_QUARTIC_H
#define CURVY_EASING_QUARTIC_H

#include "curvy/easing/curvy-easing-export.h"

#if __cplusplus
extern "C" {
#endif

extern CURVY_EASING_EXPORT float cy_quartic(float p, float start, float end);
extern CURVY_EASING_EXPORT float cy_quartic_in(float p, float start, float end);
extern CURVY_EASING_EXPORT float cy_quartic_out(float p, float start, float end);

#if __cplusplus
};
#endif


#endif
