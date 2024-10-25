// Файл main.cpp
#include <iostream>
#include "HeapInt.h"

using namespace std;

void swap(HeapInt& a, HeapInt& b) {
    HeapInt temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

void constructors()
{
    HeapInt a{5}; // 8
    HeapInt b{a}; // 9
    HeapInt c{std::move(a)}; // 10
    HeapInt d = b; // 11
    HeapInt e = std::move(b); // 12
    d = std::move(c); // 13
    d = e; // 14

    HeapInt test{10};
    swap(d, test); // 15
    cout << "d: " << d.asRef() << endl;
    cout << "test: " << test.asRef() << endl;
}

int main()
{
    constructors();
    return 0;
}