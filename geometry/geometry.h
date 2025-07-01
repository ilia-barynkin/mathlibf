#ifndef MATHLIB_VEC2F_H
#define MATHLIB_VEC2F_H

//#include "core.h"

typedef struct {
    float x;
    float y;
} Vec2f;

Vec2f vec2f_add(Vec2f a, Vec2f b);
Vec2f vec2f_sub(Vec2f a, Vec2f b);
Vec2f vec2f_scale(Vec2f v, float s);
float vec2f_dot(Vec2f a, Vec2f b);

float vec2f_len(Vec2f v);
Vec2f vec2f_norm(Vec2f v);  // безопасная нормализация (если длина > 0)

#endif
