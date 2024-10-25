#include "HeapInt.h"

// Конструктор копирования
HeapInt::HeapInt(const HeapInt& other)
{
    heapValue = new int{ *other.heapValue };
}

HeapInt::HeapInt(HeapInt&& other)
{
    heapValue = other.heapValue;
    other.heapValue = nullptr;
}

// Оператор копирующего присваивания
void HeapInt::operator=(const HeapInt& other)
{
    if (this == &other) {
        return;
    }

    delete heapValue;

    heapValue = new int{ *other.heapValue };
}

// Оператор перемещающего присваивания
void HeapInt::operator=(HeapInt&& other)
{
    if (this == &other) {
        return;
    }

    delete heapValue;

    heapValue = other.heapValue;

    other.heapValue = nullptr;
}
