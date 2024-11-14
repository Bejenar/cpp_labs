#include "dynamicArray.hpp"
#include <cassert>
#include <iostream>

void test1()
{
    DynamicArray arr = createDynamicArrayWithCapacity(10);
    assert(arr.capacity == 10);
    destroyDynamicArray(&arr);
}

void test2()
{
    DynamicArray arr = createDynamicArray();
    assert(arr.length == 0);
    addElementToArray(&arr, 5);
    assert(arr.length == 1);
    destroyDynamicArray(&arr);
}

void test3()
{
    DynamicArray arr = createDynamicArrayWithCapacity(1);
    addElementToArray(&arr, 5);
    assert(arr.capacity == 1);
    addElementToArray(&arr, 10);
    assert(arr.capacity == 2);
    addElementToArray(&arr, 20);
    assert(arr.capacity == 4);
    destroyDynamicArray(&arr);
}

void test4()
{
    DynamicArray arr = createDynamicArray();
    addElementToArray(&arr, 5);
    int el = getElementAtIndex(&arr, 0);
    assert(el == 5);
    destroyDynamicArray(&arr);
}

void test5()
{
    DynamicArray arr = createDynamicArray();
    addElementToArray(&arr, 5);
    addElementToArray(&arr, 6);
    addElementToArray(&arr, 7);

    std::span<int> span = getCurrentSpan(&arr);

    assert(span.size() == 3);
    assert(span[0] == 5);
    assert(span[1] == 6);
    assert(span[2] == 7);

    destroyDynamicArray(&arr);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
