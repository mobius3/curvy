#ifndef CURVY_TWEEN_H
#define CURVY_TWEEN_H

/**
 * @file tween.h
 *
 * This file contains the declaration of the main Curvy structure, `cy_tween`. It also contains declarations of all functions that act on it.
 */

/**
 * @defgroup main Main functions
 * @{
 *  @brief List of main functions and types related directly to `cy_tween`, including `cy_tween` itself.
 * @}
 */

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

struct cy_tween;

/**
 * @ingroup main
 * @brief Defines the function type of tween callback functions
 * @sa cy_on_seek
 * @sa cy_on_step
 * @sa cy_on_jump
 */
typedef float (*cy_tween_callback)(struct cy_tween * tween, float value);

/**
 @ingroup main
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
 * @ingroup main
 * @brief Specifies the starting value for a tween.
 * @details You can use this after `struct cy_tween` is initialized to change the starting value of a tween.
 *          Note that you can do this even *after* it has been interpolated.
 * @param tween The `struct cy_tween` value to change
 * @param value A starting value to set
 * @return The same `cy_tween` pointer passed in
 * @warning Setting the starting value of a tween *after* it has interpolated *will* interpolate it again
 *          considering the current interpolation progress
 * @sa
 * - cy_to
 */
extern CURVY_EXPORT struct cy_tween * cy_from(struct cy_tween * tween, float value);

/**
 * @ingroup main
 * @brief Adds a new interpolation step with a value target for the tween to reach
 * @details Calling this function adds a new value target (`cy_interpolation_step`) to be reached when interpolating. You can add up to
 *          `CURVY_MAX_INTERPOLATION_STEPS` (which is defined to 32 by default), each with its own easing and duration.
 *
 * **Example**
 *
 * *Adds three interpolation steps for a tween:*
 * @code
 * struct cy_tween t = {};
 * cy_from(&t, 0.0f);
 * cy_to(&t, 100.0f, cy_linear, 100.0f);
 * cy_to(&t, 200.0f, cy_circular, 100.0f);
 * cy_to(&t, 0.0f, cy_back_out, 200.0f);
 * @endcode
 *
 * **The same could be achieved using structure initialization:**
 * @code
 * struct cy_tween tween = {
 *  .from = 0.0f,
 *  .to = {
 *      { .value = 100.0f, .via = cy_linear, .during = 100.0f },
 *      { .value = 200.0f, .via = cy_circular, .during = 100.0f },
 *      { .value = 0.0f, .via = cy_back_out, .during = 200.0f }
 *  }
 * @endcode
 *
 * Starting interpolation value is set to `0.0f`, the first value to reach is `100.0f`,
 * calculated using a linear easing (`cy_linear`) in `100` duration units, moves to `200.0f` using a
 * circular easing (`cy_circular`) taking another `100` duration units to reach it and then goes back to `0.0f` using
 * a "back" easing (`cy_back_out`) in `200` duration units. Total interpolation duration is `400` duration units.
 *
 * @param tween A pointer to a `struct cy_tween` to add the new step
 * @param value The target value to reach
 * @param via The easing function to be used when interpolating
 * @param during The duration required to reach the target value
 * @return The same `cy_tween` pointer passed in
 * @warning Adding another target *after* calling any of cy_seek, cy_step or cy_jump will recalculate tween current value
 *
 * @sa
 *  - `cy_step`
 *  - `cy_seek`
 *  - `cy_jump`
 */
extern CURVY_EXPORT struct cy_tween * cy_to(struct cy_tween * tween, float value, cy_easing_fn via, float during);

/**
 * @ingroup main
 * @brief Seeks a tween to a specified duration
 *
 * It uses the stacked durations to figure out which interpolation step it should be in and then
 * calculates the correct resulting value considering the step easing function.
 *
 * **Example**:
 *
 * *Seeks to a duration in a tween with two control points*
 *
 * @code
 * // creates a tween starting from 0 with control points at durations 100 and 200
 * struct cy_tween tween = {
 *   .from = 0.0f,
 *   .to = {
 *      { .value = 1.0f, .duration = 100 },
 *      { .value = 2.0f, .duration = 100 }
 *   }
 * };
 *
 * float v = cy_seek(&tween, 150); // v = 1.5f
 * @endcode
 *
 * @param tween A pointer to a `struct cy_tween` to perform seeking
 * @param seek_duration A duration in the range `[0, total_duration]`
 * @return
 */
extern CURVY_EXPORT float cy_seek(struct cy_tween * tween, float seek_duration);
extern CURVY_EXPORT float cy_step(struct cy_tween * tween, float step_duration);
extern CURVY_EXPORT float cy_jump(struct cy_tween * tween, uint16_t jump_index);
extern CURVY_EXPORT enum cy_boolean cy_finished(struct cy_tween const * tween);

#if __cplusplus
}
#endif

#endif