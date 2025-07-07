#include "core.h"
#include <assert.h>
#include <math.h>

static void test_constrainf();
static void test_lerpf();
static void test_modf_positive();
static void test_wrapf();
static void test_sqrt_approx();

int main() {
    test_lerpf();
    test_constrainf();
    test_modf_positive();
    test_wrapf();
    test_sqrt_approx();

    return 0;
}

static void test_sqrt_approx() {
    // TODO
    float af = sqrt_approx(25.f); // M = 
    float ae = sqrtf(25.f);
    float err_abs = af - ae;
    // assert(FLOAT_EQ(sqrt_approx(0.0f), 0.0f));
    // assert(FLOAT_EQ(sqrt_approx(1.0f), 1.0f));
    // assert(FLOAT_EQ(sqrt_approx(4.0f), 2.0f));
    // assert(FLOAT_EQ(sqrt_approx(9.0f), 3.0f));
    // assert(FLOAT_EQ(sqrt_approx(100.0f), 10.0f));
    // assert(FLOAT_EQ(sqrt_approx(1e-6f), 0.001f));
    // assert(FLOAT_EQ(sqrt_approx(1e6f), 1000.0f));
}

static void test_wrapf() {
    // wrapf: base cases
    assert(FLOAT_EQ(wrapf(5.0f, 0.0f, 10.0f), 5.0f));
    assert(FLOAT_EQ(wrapf(11.0f, 0.0f, 10.0f), 1.0f));
    assert(FLOAT_EQ(wrapf(-1.0f, 0.0f, 10.0f), 9.0f));

    // non-standard bounds
    assert(FLOAT_EQ(wrapf(185.0f, -180.0f, 180.0f), -175.0f));
    assert(FLOAT_EQ(wrapf(-185.0f, -180.0f, 180.0f), 175.0f));
    assert(FLOAT_EQ(wrapf(360.0f, 0.0f, 360.0f), 0.0f));
    assert(FLOAT_EQ(wrapf(361.0f, 0.0f, 360.0f), 1.0f));

    // bound cases
    assert(FLOAT_EQ(wrapf(0.0f, 0.0f, 360.0f), 0.0f));
    assert(FLOAT_EQ(wrapf(360.0f, 0.0f, 360.0f), 0.0f));
    assert(FLOAT_EQ(wrapf(-360.0f, 0.0f, 360.0f), 0.0f));

    // same bounds
    assert(FLOAT_EQ(wrapf(123.456f, 1.0f, 1.0f), 123.456f));
}

static void test_modf_positive() {
    assert(FLOAT_EQ(modf_positive(5.0f, 3.0f), 2.0f));
    assert(FLOAT_EQ(modf_positive(3.0f, 3.0f), 0.0f));
    assert(FLOAT_EQ(modf_positive(2.9f, 3.0f), 2.9f));

    assert(FLOAT_EQ(modf_positive(-1.0f, 3.0f), 2.0f));
    assert(FLOAT_EQ(modf_positive(-4.0f, 3.0f), 2.0f));
    assert(FLOAT_EQ(modf_positive(-3.0f, 3.0f), 0.0f));

    assert(FLOAT_EQ(modf_positive(7.5f, 5.0f), 2.5f));
    assert(FLOAT_EQ(modf_positive(-7.5f, 5.0f), 2.5f));

    assert(FLOAT_EQ(modf_positive(-0.1f, 1.0f), 0.9f));
    assert(FLOAT_EQ(modf_positive(-2.0f, 2.0f), 0.0f));

    assert(FLOAT_EQ(modf_positive(-5.0f, 3.0f), 1.0f));
}

static void test_lerpf() {
    // lerpf: base cases
    assert(FLOAT_EQ(lerpf(0.0f, 1.0f, 0.0f), 0.0f));
    assert(FLOAT_EQ(lerpf(0.0f, 1.0f, 1.0f), 1.0f));
    assert(FLOAT_EQ(lerpf(0.0f, 1.0f, 0.5f), 0.5f));

    // non-symmetrical
    assert(FLOAT_EQ(lerpf(-1.0f, 1.0f, 0.75f), 0.5f));
    assert(FLOAT_EQ(lerpf(10.0f, 20.0f, 0.25f), 12.5f));

    // extrapolation
    assert(FLOAT_EQ(lerpf(0.0f, 1.0f, -1.0f), -1.0f));
    assert(FLOAT_EQ(lerpf(0.0f, 1.0f, 2.0f), 2.0f));
}

static void test_constrainf() {
    // inside 
    assert(FLOAT_EQ(constrainf(5.0f, 1.0f, 10.0f), 5.0f));
    assert(FLOAT_EQ(constrainf(1.0f, 1.0f, 10.0f), 1.0f));
    assert(FLOAT_EQ(constrainf(10.0f, 1.0f, 10.0f), 10.0f));

    // lesser than min
    assert(FLOAT_EQ(constrainf(-100.0f, -10.0f, 10.0f), -10.0f));
    assert(FLOAT_EQ(constrainf(-1.0f, 0.0f, 100.0f), 0.0f));

    // higher than max
    assert(FLOAT_EQ(constrainf(200.0f, 0.0f, 100.0f), 100.0f));
    assert(FLOAT_EQ(constrainf(9.9f, -5.0f, 5.0f), 5.0f));

    // boundary conditions: min == max
    assert(FLOAT_EQ(constrainf(0.0f, 2.0f, 2.0f), 2.0f));
    assert(FLOAT_EQ(constrainf(100.0f, 100.0f, 100.0f), 100.0f));
    assert(FLOAT_EQ(constrainf(-100.0f, -5.0f, -5.0f), -5.0f));
}