#ifndef CURVY_EASING_QUINTIC_H
#define CURVY_EASING_QUINTIC_H

#include "curvy/easing/curvy-easing-export.h"

#if __cplusplus
extern "C" {
#endif

extern CURVY_EASING_EXPORT float cy_quintic(float p, float start, float end);
extern CURVY_EASING_EXPORT float cy_quintic_in(float p, float start, float end);
extern CURVY_EASING_EXPORT float cy_quintic_out(float p, float start, float end);

#if __cplusplus
};
#endif


#endif
