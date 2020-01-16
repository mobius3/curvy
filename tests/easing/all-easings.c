#include <curvy/easing/linear.h>
#include <curvy/easing/back.h>
#include <curvy/easing/bounce.h>
#include <curvy/easing/circular.h>

#include "criterion/criterion.h"
#include "test-easing-fn.h"

Test(easing, linear_easing_return_expected_values) {
  float at[] = { 0, 0.5f, 1.0f }, expected[] = { 0.0f, 0.5f, 1.0f };
  test_easing_fn(cy_linear, 0, 1, at, expected, 3);
}


Test(easing, back_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.5f, 0.9f, 1.0f }, expected[] = { 0.000000f, -0.037519f, 0.500000f, 1.037519f, 1.000000f };
  test_easing_fn(cy_back, 0, 1, at, expected, 5);
}

Test(easing, back_in_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.5f, 0.9f, 1.0f }, expected[] = { 0.000000f, -0.014314f, -0.087698f, 0.591172f, 1.000000f };
  test_easing_fn(cy_back_in, 0, 1, at, expected, 5);
}

Test(easing, back_out_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.5f, 0.9f, 1.0f }, expected[] = { 0.000000f, 0.408828f, 1.087698f, 1.014314f, 1.000000f };
  test_easing_fn(cy_back_out, 0, 1, at, expected, 5);
}

Test(easing, bounce_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = {
      0.000000f, 0.030000f, 0.113750f, 0.045000f, 0.348750f, 0.500000f,
      0.651250f, 0.955000f, 0.886250f, 0.970000f, 1.000000f
  };
  test_easing_fn(cy_bounce, 0, 1, at, expected, 11);
}

Test(easing, bounce_in_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = {
      0.000000f, 0.011875f, 0.060000f, 0.069375f, 0.227500f, 0.234375f,
      0.090000f, 0.319375f, 0.697500f, 0.924375f, 1.000000f
  };
  test_easing_fn(cy_bounce_in, 0, 1, at, expected, 11);
}

Test(easing, bounce_out_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
  expected[] = {
      0.000000f, 0.075625f, 0.302500f, 0.680625f, 0.910000f, 0.765625f,
      0.772500f, 0.930625f, 0.940000f, 0.988125f, 1.000000f
  };
  test_easing_fn(cy_bounce_out, 0, 1, at, expected, 11);
}

Test(easing, circular_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
  expected[] = { 0.000000f, 0.010102f, 0.041742f, 0.100000f, 0.200000f, 0.500000f,
                 0.800000f, 0.900000f, 0.958258f, 0.989898f, 1.000000f };
  test_easing_fn(cy_circular, 0, 1, at, expected, 11);
}

Test(easing, circular_in_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
  expected[] = { 0.000000f, 0.005013f, 0.020204f, 0.046061f, 0.083485f, 0.133975f,
                     0.200000f, 0.285857f, 0.400000f, 0.564110f, 1.000000f };
  test_easing_fn(cy_circular_in, 0, 1, at, expected, 11);
}

Test(easing, circular_out_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
  expected[] = { 0.000000f, 0.435890f, 0.600000f, 0.714143f, 0.800000f, 0.866025f,
                     0.916515f, 0.953939f, 0.979796f, 0.994987f, 1.000000f };
  test_easing_fn(cy_circular_out, 0, 1, at, expected, 11);
}