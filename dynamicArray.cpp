#include "dynamicArray.hpp"
#include <cassert>
#include <cstdlib>
#include <cstring>

static void resizeArray(DynamicArray* array, int newCapacity)
{
    int* newData = (int*)std::malloc(newCapacity * sizeof(int));
    std::memcpy(newData, array->data, array->length * sizeof(int));
    std::free(array->data);
    array->data = newData;
    array->capacity = newCapacity;
}

DynamicArray createDynamicArrayWithCapacity(int capacity)
{
    assert(capacity > 0);
    DynamicArray array;
    array.data = (int*)std::malloc(capacity * sizeof(int));
    array.length = 0;
    array.capacity = capacity;
    return array;
}

DynamicArray createDynamicArray()
{
    return createDynamicArrayWithCapacity(4);
}

void addElementToArray(DynamicArray* array, int value)
{
    if (array->length >= array->capacity)
    {
        resizeArray(array, array->capacity * 2);
    }
    array->data[array->length++] = value;
}

int getElementAtIndex(const DynamicArray* array, int index)
{
    assert(index >= 0 && index < array->length);
    return array->data[index];
}

std::span<int> getCurrentSpan(const DynamicArray* array)
{
    return std::span<int>(array->data, array->length);
}

void destroyDynamicArray(DynamicArray* array)
{
    std::free(array->data);
    array->data = nullptr;
    array->length = 0;
    array->capacity = 0;
}
