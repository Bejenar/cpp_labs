#pragma once

#include <cassert>
#include <span>

struct DynamicArray
{
    int* data;
    int length;
    int capacity;
};

DynamicArray createDynamicArrayWithCapacity(int capacity);
DynamicArray createDynamicArray();
void addElementToArray(DynamicArray* array, int value);
int getElementAtIndex(const DynamicArray* array, int index);
std::span<int> getCurrentSpan(const DynamicArray* array);
void destroyDynamicArray(DynamicArray* array);

