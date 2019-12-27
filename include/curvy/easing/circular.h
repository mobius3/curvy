#ifndef CURVY_EASING_CIRCULAR_H
#define CURVY_EASING_CIRCULAR_H

#include "curvy/easing/curvy-easing-export.h"

#if __cplusplus
extern "C" {
#endif

extern CURVY_EASING_EXPORT float cy_circular(float p, float start, float end);
extern CURVY_EASING_EXPORT float cy_circular_in(float p, float start, float end);
extern CURVY_EASING_EXPORT float cy_circular_out(float p, float start, float end);

#if __cplusplus
};
#endif


#endif
