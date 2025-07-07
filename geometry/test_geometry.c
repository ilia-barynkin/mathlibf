#include "geometry.h"
#include "core.h"
#include <stdio.h>
#include <math.h>

int assert_vec2f_eq(Vec2f a, Vec2f b) {
    return FLOAT_EQ(a.x, b.x) && FLOAT_EQ(a.y, b.y);
}

float abs_err_vec2f(Vec2f a, Vec2f b) {
    float res = sqrtf((a.x - b.x)*(a.x - b.x) +
        (a.y - b.y)*(a.y - b.y));
        
    return res;
}

float rel_err_vec2f(Vec2f a, Vec2f b) {
    float len_err = sqrtf(b.x*b.x + b.y*b.y);
    return abs_err_vec2f(a, b) / len_err;  
}

void test_vec2f_add();
void test_vec2f_sub();
void test_vec2f_scale();
void test_vec2f_dot();
void test_vec2f_len();
void test_vec2f_norm();
void test_vec2f_dist();
void test_vec2f_rotate();
void test_vec2f_perp_ccw();
void test_vec2f_angle_between();

int main() {
    test_vec2f_add();
    test_vec2f_sub();
    test_vec2f_scale();
    test_vec2f_dot();
    test_vec2f_len();
    test_vec2f_norm();
    test_vec2f_dist();
    test_vec2f_rotate();
    test_vec2f_perp_ccw();
    test_vec2f_angle_between();
    return 0;
}

void test_vec2f_add() {
    Vec2f a = {1.f, 2.f};
    Vec2f b = {3.f, -1.f};
    Vec2f result = vec2f_add(a, b);
    Vec2f expected = {4.f, 1.f};
    if (!assert_vec2f_eq(result, expected)) {
        printf("vec2f_add failed\n");
    }
}

void test_vec2f_sub() {
    Vec2f a = {5.f, 4.f};
    Vec2f b = {2.f, 1.f};
    Vec2f result = vec2f_sub(a, b);
    Vec2f expected = {3.f, 3.f};
    if (!assert_vec2f_eq(result, expected)) {
        printf("vec2f_sub failed\n");
    }
}

void test_vec2f_scale() {
    Vec2f v = {2.f, -3.f};
    float s = 0.5f;
    Vec2f result = vec2f_scale(v, s);
    Vec2f expected = {1.f, -1.5f};
    if (!assert_vec2f_eq(result, expected)) {
        printf("vec2f_scale failed\n");
    }
}

void test_vec2f_dot() {
    Vec2f a = {1.f, 2.f};
    Vec2f b = {3.f, 4.f};
    float result = vec2f_dot(a, b);
    float expected = 11.f;
    if (!FLOAT_EQ(result, expected)) {
        printf("vec2f_dot failed\n");
    }
}

void test_vec2f_len() {
    Vec2f v = {3.f, 4.f};
    float result = vec2f_len(v);
    float expected = 5.f;
    if (!FLOAT_EQ(result, expected)) {
        float err = REL_ERR(result, expected);
        printf("test_vec2f_len rel error %f", err);
    }
}

void test_vec2f_norm() {
    Vec2f v = {0.f, 5.f};
    Vec2f result = vec2f_norm(v);
    Vec2f expected = {0.f, 1.f};

    if (!assert_vec2f_eq(result, expected)) {
        float err = rel_err_vec2f(result, expected);
        printf("test_vec2f_norm rel error %f", err);
    }

    // TODO
    // Vec2f zero = {0.f, 0.f};
    // Vec2f result_zero = vec2f_norm(zero);
}

void test_vec2f_dist() {
    Vec2f a = {0.f, 0.f};
    Vec2f b = {3.f, 4.f};
    float result = vec2f_dist(a, b);
    float expected = 5.f;
    if (!FLOAT_EQ(result, expected)) {
        printf("vec2f_dist failed: got %.6f\n", result);
    }
}

void test_vec2f_rotate() {
    Vec2f v = {1.f, 0.f};
    float angle = 3.1415926f / 2.0f; // 90°
    Vec2f rotated = vec2f_rotate(v, angle);
    Vec2f expected = {0.f, 1.f};
    if (!assert_vec2f_eq(rotated, expected)) {
        printf("vec2f_rotate failed: got (%.6f, %.6f)\n", rotated.x, rotated.y);
    }
}

void test_vec2f_perp_ccw() {
    Vec2f v = {2.f, 0.f};
    Vec2f perp = vec2f_perp_ccw(v);
    Vec2f expected = {0.f, 2.f};
    if (!assert_vec2f_eq(perp, expected)) {
        printf("vec2f_perp_ccw failed\n");
    }
}

void test_vec2f_angle_between() {
    Vec2f a = {1.f, 0.f};
    Vec2f b = {0.f, 1.f};
    float angle = vec2f_angle_between(a, b);
    float expected = 3.1415926f / 2.0f;
    if (!FLOAT_EQ(angle, expected)) {
        printf("vec2f_angle_between failed: got %.6f\n", angle);
    }
}