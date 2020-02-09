#include <curvy/easing/linear.h>
#include <curvy/easing/back.h>
#include <curvy/easing/bounce.h>
#include <curvy/easing/circular.h>
#include <curvy/easing/cubic.h>
#include <curvy/easing/elastic.h>
#include <curvy/easing/exponential.h>

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

Test(easing, cubic_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = { 0.000000f, 0.004000f, 0.032000f, 0.108000f, 0.256000f, 0.500000f,
                     0.744000f, 0.892000f, 0.968000f, 0.996000f, 1.000000f };
  test_easing_fn(cy_cubic, 0, 1, at, expected, 11);
}

Test(easing, cubic_in_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = { 0.000000f, 0.001000f, 0.008000f, 0.027000f, 0.064000f, 0.125000f,
                     0.216000f, 0.343000f, 0.512000f, 0.729000f, 1.000000f };
  test_easing_fn(cy_cubic_in, 0, 1, at, expected, 11);
}

Test(easing, cubic_out_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = { 0.000000f, 0.271000f, 0.488000f, 0.657000f, 0.784000f, 0.875000f,
                     0.936000f, 0.973000f, 0.992000f, 0.999000f, 1.000000f };
  test_easing_fn(cy_cubic_out, 0, 1, at, expected, 11);
}


Test(easing, elastic_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = { 0.000000f, 0.021572f, 0.071311f, 0.213959f, 0.536581f, 0.216257f,
                     1.152521f, 1.123724f, 1.051097f, 1.017306f, 1.000000f };
  test_easing_fn(cy_elastic, 0, 1, at, expected, 11);
}

Test(easing, elastic_in_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = { 0.000000f, 0.000977f, -0.003383f, -0.003906f, 0.013532f, 0.015625f,
                    -0.054127f, -0.062500f, 0.216506f, 0.250000f, 1.000000f };
  test_easing_fn(cy_elastic_in, 0, 1, at, expected, 11);
}

Test(easing, elastic_out_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = { 0.000000f, 1.250000f, 1.125000f, 0.875000f, 1.031250f, 1.015625f,
                     0.984375f, 1.003906f, 1.001953f, 0.998047f, 1.000000f };
  test_easing_fn(cy_elastic_out, 0, 1, at, expected, 11);
}

Test(easing, exponential_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = { 0.000488f, 0.001953f, 0.007812f, 0.031250f, 0.125000f, 0.500000f,
                     0.875000f, 0.968750f, 0.992188f, 0.998047f, 0.999512f };
  test_easing_fn(cy_exponential, 0, 1, at, expected, 11);
}

Test(easing, exponential_in_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = { 0.000977f, 0.001953f, 0.003906f, 0.007812f, 0.015625f, 0.031250f,
                     0.062500f, 0.125000f, 0.250000f, 0.500000f, 1.000000f };
  test_easing_fn(cy_exponential_in, 0, 1, at, expected, 11);
}

Test(easing, exponential_out_easing_return_expected_values) {
  float at[] = { 0, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f, 1.0f },
      expected[] = { 0.000000f, 0.500000f, 0.750000f, 0.875000f, 0.937500f, 0.968750f,
                     0.984375f, 0.992188f, 0.996094f, 0.998047f, 0.999023f };
  test_easing_fn(cy_exponential_out, 0, 1, at, expected, 11);
}