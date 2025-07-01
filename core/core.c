#include "core.h"

float absf(float x) {
    return x < 0.f ? x * (-1.f) : x;
}

int absi(int x) {
    return x < 0 ? -x : x;
}

float modf_positive(float x, float y) {
    int div = (int)(x / y);
    float modf = absf(x - div * y);
    return (modf == 0.f || x > 0.f) ? modf : y - modf;
}

float constrainf(float x, float min, float max) {
    return x > max ? max : x < min ? min : x;
}

float lerpf(float a, float b, float t) {
    return (b - a) * t + a;
}

float wrapf(float x, float min, float max) {
    if (FLOAT_EQ(min, max)) return x;
    return min + modf_positive(x - min, max - min);
}