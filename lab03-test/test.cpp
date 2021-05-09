#include "../histogram.h"
#include "../check.h"
#include <cassert>

void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_same_numbers()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_single()
{
    double min=0;
    double max=0;
    find_minmax({1},min,max);
    assert(min == 1);
    assert(max == 1);
}

void test_empty ()
{
    double min=0;
    double max=0;
    find_minmax({},min,max);
}

void test_color_1()
{
    string stroke("RED");
    bool result = check_color(stroke);
    assert(result == false);
}

void test_color_2()
{
    string stroke("pink");
    bool result = check_color(stroke);
    assert(result == true);
}


int main()
{
    test_positive();
    test_negative();
    test_same_numbers();
    test_single();
    test_empty ();
    test_color_1();
    test_color_2();

}
