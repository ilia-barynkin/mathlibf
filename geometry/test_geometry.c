#include "geometry.h"
#include <assert.h>

static void test_basic_arithmetic();

int main() {
    test_basic_arithmetic();

    return 0;
}

void test_basic_arithmetic() {
    Vec2f a = {1.0f, 2.0f};
    Vec2f b = {3.0f, -1.0f};

    Vec2f r;

    r = vec2f_add(a, b);
    assert(FLOAT_EQ(r.x, 4.0f));
    assert(FLOAT_EQ(r.y, 1.0f));

    r = vec2f_sub(a, b);
    assert(FLOAT_EQ(r.x, -2.0f));
    assert(FLOAT_EQ(r.y, 3.0f));

    r = vec2f_scale(a, 2.0f);
    assert(FLOAT_EQ(r.x, 2.0f));
    assert(FLOAT_EQ(r.y, 4.0f));

    assert(FLOAT_EQ(vec2f_dot(a, b), (1.0f * 3.0f + 2.0f * -1.0f)));  // = 1.0f

}