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

// IEEE754, 32 bit float
#define MANTISSA_SZ 23
#define SGN_SZ 1
#define EXP_BIAS 127
#define MANTISSA_MASK  0x7fffff
#define MANTISSA_COMPL 0x1000000
#define FROM_Q16_to_Q23 0x80 // 2 ^ 23 / 2 ^ 16 = 2 ^ 7 

typedef union {
    float f; 
    unsigned int u;
} uf_t;

// TODO: need more everything
float sqrt_approx_newt(float x, int steps) {
    uf_t v = *(uf_t*)(&x);

    unsigned int M = (v.u & MANTISSA_MASK);

    // first-time newton approx around 1.6 on Q16 (fixed-point)
    v.u = (v.u >> 23) & 0xFF;
    
    M = 72818 + ((M * 5) >> 11);

    M = (v.u & 1) ? (M * 92686) : M; // consider sqrt(2) if exponent is odd
    M = (M * FROM_Q16_to_Q23) & MANTISSA_MASK;
    v.u = ((v.u - EXP_BIAS) >> 1) + EXP_BIAS;
    v.u = (v.u << 23) | M;

    return v.f;
}