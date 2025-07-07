#ifndef MATHLIB_VEC2F_H
#define MATHLIB_VEC2F_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float x;
    float y;
} Vec2f;

Vec2f vec2f_add(Vec2f a, Vec2f b);
Vec2f vec2f_sub(Vec2f a, Vec2f b);
Vec2f vec2f_scale(Vec2f v, float s);
float vec2f_dot(Vec2f a, Vec2f b);

float vec2f_len(Vec2f v);
Vec2f vec2f_norm(Vec2f v);

// Euclidean distance between two points
float vec2f_dist(Vec2f a, Vec2f b);

// CCW rotation of a vector v on angle_rad
Vec2f vec2f_rotate(Vec2f v, float angle_rad);

// Perpendicular to v rotated by PI/2 CCW
Vec2f vec2f_perp_ccw(Vec2f v);

// Angle between [0, PI] between two vectors
float vec2f_angle_between(Vec2f a, Vec2f b);

#ifdef __cplusplus
}
#endif

#endif
