#ifndef CURVY_EASING_CUBIC_H
#define CURVY_EASING_CUBIC_H

#include "curvy/easing/curvy-easing-export.h"

#if __cplusplus
extern "C" {
#endif

extern CURVY_EASING_EXPORT float cy_cubic(float p, float start, float end);
extern CURVY_EASING_EXPORT float cy_cubic_in(float p, float start, float end);
extern CURVY_EASING_EXPORT float cy_cubic_out(float p, float start, float end);

#if __cplusplus
};
#endif


#endif
