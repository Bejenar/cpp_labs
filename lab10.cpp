#include <cassert>
#include "Vector2.hpp"

int main() {
    Vector2 v{1.0f, 2.0f};
    Vector2 w{3.0f, 4.0f};

    assert(((v * 2.0f) == Vector2{2.0f, 4.0f}));
    assert(((2.0f * v) == Vector2{2.0f, 4.0f}));
    v *= 2.0f;
    assert((v == Vector2{2.0f, 4.0f}));
    v /= 2.0f;
    assert((v == Vector2{1.0f, 2.0f}));
    assert(((v + w) == Vector2{4.0f, 6.0f}));
    assert(((v - w) == Vector2{-2.0f, -2.0f}));
    v += w;
    assert((v == Vector2{4.0f, 6.0f}));
    v -= w;
    assert((v == Vector2{1.0f, 2.0f}));
    assert(v[0] == 1.0f);
    assert(v[1] == 2.0f);

    v[0] = 3.0f;
    std::cout << v << std::endl;

    return 0;
}