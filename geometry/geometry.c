#include "geometry.h"

Vec2f vec2f_add(Vec2f a, Vec2f b) {
    return (Vec2f){
        .x = a.x + b.x,
        .y = b.x + b.y 
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
    return 0; // todo
}

Vec2f vec2f_norm(Vec2f v)
{
    return (Vec2f){
        .x = 0.f, 
        .y = 0.f
    };
}