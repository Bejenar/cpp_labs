#include <iostream>
#include <string.h>

struct TwoInts
{
    int a;
    int b;
};

struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    // Инициализация структуры
    TwoInts i2 = { };
    i2.a = 5;
    i2.b = 7;

    std::cout << i2.a << std::endl; // 5
    std::cout << i2.b << std::endl; // 7

    // Инциализация структуры
    StructWithArray s = { };
    s.arr[0] = 10; // Изменение значения элемента массива

    // Инициализация структуры
    StructWithArray s1 = { };
    s1.arr[0] = 15; // Изменение значения элемента массива

    // Указатель на первую структуру
    StructWithArray* sPointer = &s;
    sPointer->arr[0] = 20; // 10 заменяется на 20

    std::cout << s.arr[0] << std::endl; // 20
    s.arr[0] = 25;
    std::cout << s.arr[0] << std::endl; // 25
    sPointer->arr[0] = 30;
    std::cout << s.arr[0] << std::endl; // 30

    // теперь указатель указывает на вторую структуру
    sPointer = &s1;
    sPointer->arr[0] = 35;
    std::cout << s.arr[0] << std::endl; // 30
    std::cout << s1.arr[0] << std::endl; // 35

    // Инициализация массива структур
    StructWithArray structArray[2] = { };
    structArray[0].arr[3] = 77;
    structArray[1].someNumber = &structArray[0].arr[3]; // указатель на элемент массива


    sPointer = &s;
    int* pointer = &sPointer->arr[3];
    s.arr[3] = 72;
    std::cout << *pointer; // 72

    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray)); // Заполнение памяти нулями
    return 0;
}