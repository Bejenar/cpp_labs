#pragma once // 1
#include <cassert>

class HeapInt
{
private:
    int* heapValue; // 2

public:
    // 3
    inline HeapInt(int val)
        // 4
        : heapValue(new int{ val })
    {
    }

    inline ~HeapInt()
    {
        // Заметка: delete проверяет на nullptr сам.
        delete heapValue; // 5
    }

    inline int& asRef()
    {
        assert(heapValue != nullptr); // 6
        return *heapValue;
    }

    // add explicit to restrict (11) (12)
    HeapInt(const HeapInt& other); // 7
    HeapInt(HeapInt&& other);
    void operator=(const HeapInt& Other);
    void operator=(HeapInt&& other);
};