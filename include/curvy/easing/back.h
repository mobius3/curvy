#ifndef CURVY_EASING_BACK_H
#define CURVY_EASING_BACK_H

#include "curvy/easing/curvy-easing-export.h"

#if __cplusplus
extern "C" {
#endif

  /**
   * @ingroup easing-functions
   * @brief An easing function that has a "cute" natural coming back effect. The effect is applied both in and out.
   * @param p a float number between `0` and `1`. `0` returns start, `1` returns `end`
   * @param start the starting value
   * @param end the end value
   * @return A number between [start, end] calculated according to this easing function
   */
extern CURVY_EASING_EXPORT float cy_back(float p, float start, float end);

/**
 * @ingroup easing-functions
 * @brief An easing function that has a "cute" natural coming back effect. The effect is applied easing in.
 * @param p a float number between `0` and `1`. `0` returns start, `1` returns `end`
 * @param start the starting value
 * @param end the end value
 * @return A number between [start, end] calculated according to this easing function
 */
extern CURVY_EASING_EXPORT float cy_back_in(float p, float start, float end);

/**
 * @ingroup easing-functions
 * @brief An easing function that has a "cute" natural coming back effect. The effect is applied easing out.
 * @param p a float number between `0` and `1`. `0` returns start, `1` returns `end`
 * @param start the starting value
 * @param end the end value
 * @return A number between [start, end] calculated according to this easing function
 */
extern CURVY_EASING_EXPORT float cy_back_out(float p, float start, float end);

#if __cplusplus
};
#endif


#endif
