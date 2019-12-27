#ifndef CURVY_EASING_BOUNCE_H
#define CURVY_EASING_BOUNCE_H

#include "curvy/easing/curvy-easing-export.h"

#if __cplusplus
extern "C" {
#endif

extern CURVY_EASING_EXPORT float cy_bounce(float p, float start, float end);
extern CURVY_EASING_EXPORT float cy_bounce_in(float p, float start, float end);
extern CURVY_EASING_EXPORT float cy_bounce_out(float p, float start, float end);

#if __cplusplus
};
#endif


#endif
