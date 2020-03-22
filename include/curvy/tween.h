#ifndef CURVY_TWEEN_H
#define CURVY_TWEEN_H

#include "curvy/curvy-export.h"
#include "curvy/control-point.h"
#include "curvy/boolean.h"

#include <stdlib.h>
#include <inttypes.h>

#if __cplusplus
extern "C" {
#endif

#ifndef CURVY_MAX_CONTROL_POINTS
#define CURVY_MAX_CONTROL_POINTS 32
#endif

/**
 * @brief Defines the function type of tween callback functions
 * @sa cy_on_seek
 * @sa cy_on_step
 * @sa cy_on_jump
 */
struct cy_tween;
typedef float (*cy_tween_callback)(struct cy_tween * tween, float value);

/**
 @brief Tweening main structure. It holds all necessary information and control points to interpolate.

 All fields in this structure must be considered **private**, except when initializing. Changing its
 fields after the structure has been initialized can result in unexpected behavior.

 This structure, when used, MUST BE either zeroed or initialized. Using this structure uninitialized WILL
 result in undefined behavior and potentially crashes.

 To initialize an empty `struct cy_tween` you can either use `memset` or initialize to an empty object:

 @code
 // both bellow are equivalent
 struct cy_tween tween = {}; // initializes all fields to zero
 memset(&tween, 0, sizeof(tween)); // uses memset to zero all fields
 @endcode

 You can also, when using [struct initialization](https://en.cppreference.com/w/c/language/struct_initialization),
 declare `from` and `to` values:

 @code
 struct cy_tween tween = {
   .from = 0.0f,
   .to = { 1.0f, .via = cy_linear, .during = 100 }
 };
 @endcode
 All other fields will be initialized to zero.

*/
struct cy_tween {
  float from;
  uint16_t to_count;


  cy_tween_callback on_step;
  cy_tween_callback on_seek;

  float value;
  float duration;
  float current_duration;
  uint8_t initialized;

  struct cy_control_point to[CURVY_MAX_CONTROL_POINTS];
};

/**
 * @brief Specifies the starting value for a tween.
 * @details You can use this after `struct cy_tween` is initialized to change the starting value of a tween.
 *          Note that you can do this even *after* it has been interpolated.
 * @param tween The `struct cy_tween` value to change
 * @param value A starting value to set
 * @return @p tween
 * @warning Setting the starting value of a tween *after* it has interpolated *will* interpolate it again
 *          considering the current interpolation progress
 */
extern CURVY_EXPORT struct cy_tween * cy_from(struct cy_tween * tween, float value);

/**
 * @brief Adds a new value target for the tween to reach
 * @details Calling this function adds a new value target ("control point") to be reached when interpolating. You can add up to
 *          `CURVY_MAX_CONTROL_POINTS` (which is defined to 32 by default), each with its own easing and duration.
 *
 * **Example:**
 *
 * *Adds three control points for a tween:*
 * @code
 * struct cy_tween t = {};
 * cy_from(&t, 0.0f);
 * cy_to(&t, 1.0f, cy_linear, 100.0f);
 * cy_to(&t, 2.0f, cy_circular, 100.0f);
 * cy_to(&t, 0.0f, cy_back_out, 200.0f);
 * @endcode
 *
 * @param tween The `struct cy_tween` value to change
 * @param value A starting value to set
 * @param via The easing function to be used when interpolating
 * @param during How many steps required to reach target value
 * @return @p tween
 * @warning Adding another target *after* calling any of cy_seek, cy_step or cy_jump will recalculate tween current value
 */
extern CURVY_EXPORT struct cy_tween * cy_to(struct cy_tween * tween, float value, cy_easing_fn via, float during);

extern CURVY_EXPORT float cy_seek(struct cy_tween * tween, float seek_duration);
extern CURVY_EXPORT float cy_step(struct cy_tween * tween, float step_duration);
extern CURVY_EXPORT float cy_jump(struct cy_tween * tween, uint16_t jump_index);
extern CURVY_EXPORT enum cy_boolean cy_finished(struct cy_tween const * tween);

#if __cplusplus
}
#endif

#endif