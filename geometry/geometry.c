#include "geometry.h"
#include "core.h"

Vec2f vec2f_add(Vec2f a, Vec2f b) {
    return (Vec2f){
        .x = a.x + b.x,
        .y = a.y + b.y 
    };
}

Vec2f vec2f_sub(Vec2f a, Vec2f b) {
    return (Vec2f){
        .x = a.x - b.x,
        .y = a.y - b.y
    };
}

Vec2f vec2f_scale(Vec2f v, float s){
    return (Vec2f){
        .x = s * v.x,
        .y = s * v.y
    };
}

float vec2f_dot(Vec2f a, Vec2f b){
    return a.x * b.x + a.y * b.y;
}

float vec2f_len(Vec2f v) {
    return sqrt_approx(v.x * v.x + v.y * v.y);
}

Vec2f vec2f_norm(Vec2f v) {
    return vec2f_scale(v, 1.f/vec2f_len(v));
}

float vec2f_dist(Vec2f a, Vec2f b) {
    return vec2f_len(vec2f_sub(b, a));
}

Vec2f vec2f_rotate(Vec2f v, float angle_rad) {
    
}

// Perpendicular to v rotated by PI/2 CCW
Vec2f vec2f_perp_ccw(Vec2f v);

// Angle between [0, PI] between two vectors
float vec2f_angle_between(Vec2f a, Vec2f b);