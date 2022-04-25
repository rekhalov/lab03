#include "histogram.h"
#include "svg.h"
#include <cassert>

void
test_positive() {
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void
test_negative() {
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void
test_same() {
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void
test_onenumb() {
    double min = 0;
    double max = 0;
    find_minmax({1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_void(){
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);

}

void test_heigth_min(){
    size_t height = 4;
    test_height(height,4,700);
    assert(height == 4);
}

void test_heigth_max(){
    size_t height = 200;
    test_height(height,4,700);
    assert(height == (700/4));
}

void test_heigth_equal(){
    size_t height = 175;
    test_height(height,4,700);
    assert(height == 175);
}

int
main() {
    test_positive();
    test_negative();
    test_same();
    test_onenumb();
    test_void();
    test_heigth_min();
    test_heigth_max();
    test_heigth_equal();
}
