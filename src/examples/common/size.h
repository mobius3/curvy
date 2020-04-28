#ifndef CURVY_EXAMPLES_COMMON_SIZE_H
#define CURVY_EXAMPLES_COMMON_SIZE_H

#if __cplusplus
extern "C" {
#endif

struct cyex_size {
  float width;
  float height;
};

struct cyex_size cyex_make_size(float width, float height);


#if __cplusplus
};
#endif

#endif