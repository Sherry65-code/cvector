#ifndef CVECTOR_H
#define CVECTOR_H

#include <stdlib.h>

#define DEFINE_VECTOR(type) \
typedef struct {  \
  size_t capacity;  \
  size_t length;  \
  type* data; \
} Vector_##type;  \
\
Vector_##type* cvector_init_##type() {  \
  Vector_##type* vec = (Vector_##type*)malloc(sizeof(Vector_##type));\
  vec->capacity = 1; \
  vec->length = 0; \
  vec->data = (type*)malloc(vec->capacity * sizeof(type)); \
  return vec; \
} \
\
void cvector_push_back_##type(Vector_##type* vec, type value) { \
  if (vec->length >= vec->capacity) {\
    vec->capacity *= 2; \
    vec->data = realloc(vec->data, vec->capacity * sizeof(type)); \
  } \
  vec->data[vec->length++] = value; \
} \
\
void cvector_resize_##type(Vector_##type* vec, size_t newsize) { \
  if (newsize <= 0) return; \
  vec->capacity = newsize; \
  vec->data = realloc(vec->data, vec->capacity * sizeof(type)); \
}\
\
void cvector_shrink_to_fit_##type(Vector_##type* vec) { \
  vec->capacity = vec->length; \
  vec->data = realloc(vec->data, vec->capacity * sizeof(type)); \
} \
\
type cvector_front_##type(Vector_##type* vec) { \
  return vec->data[0]; \
} \
\
type cvector_back_##type(Vector_##type* vec) { \
  return vec->data[vec->length-1]; \
} \
\
void cvector_pop_out_##type(Vector_##type* vec) {\
  if (vec->length == 0) return; \
  vec->length--; \
}\

#endif
