#ifndef MATHLIB_CORE_H
#define MATHLIB_CORE_H

#ifdef __cplusplus
extern "C" {
#endif

#define EPSILON 1e-6f
// Default comparison threshold for FLOAT_EQ.
#define FLOAT_EQ(a, b) (absf((a)-(b)) < EPSILON)
#define ABS_ERR(a, b) (absf((a) - (b)))
#define REL_ERR(a, b) (ABS_ERR(a, b)/(b))
// Common macros for cross-module usage:
#define MATHLIB_INLINE static inline

// Returns position on a circular interval of length y after rotating by x.
// Result is always in [0, y). Like fmodf(x, y), but always positive.
// Think of it as walking x units along the perimeter of a circle of length y.
// Tl;dr: just remember school trigonometry class.
float modf_positive(float x, float y);
// Absolute value.
float absf(float x);
// Clamps `x` between [min, max].
float constrainf(float x, float min, float max);
// Linear interpolation between a & b with argument t ∈ [0.0, 1.0].
float lerpf(float a, float b, float t);
// Wrapping x in a half-opened [min, max) interval.
// If min == max, returns x without wrapping.
float wrapf(float x, float min, float max);
float sqrt_approx(float x);

#ifdef __cplusplus
}
#endif

#endif // MATHLIB_CORE_H
