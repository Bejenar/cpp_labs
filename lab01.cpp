#include <iostream>

// #define print() printf("i=%i; number=%i; iPointer=%i", i, number, *iPointer);

int main() {
    int a = 2;
    int &refA = a;
    int *ar = &a;
    std::cout << ar << std::endl;
    ar = &refA;
    std::cout << ar << std::endl;

    a = 5;


    // Объявить i типа инт
    int i;
    int number;
    int *iPointer;
    // Определить группу переменных (массив) из 3 элементов (инициализированных на 0)
    int arr[3]{};

    auto print = [&]() {
        printf("i=%i; number=%i; iPointer=%i\n"
               "arr[0]=%i\narr[1]=%i\narr[2]=%i\n---------\n", i, number, *iPointer, arr[0], arr[1], arr[2]);
    };
    // Инициализировать на 69
    i = 69;
    // Определить переменную number типа инт, дать значение 72
    number = 72;
    // Перезаписать значение i на 69 + 72 (т.е. i + number)
    i = i + number;

    // Создать указатель на i (iPointer)
    iPointer = &i;
    print();
    // Считать данные по адресу из указателя в переменную number
    number = *iPointer;
    // Вписать в i через указатель значение 15
    *iPointer = 15;
    print();
    // Сменить адрес в iPointer на адрес первого элемента массива
    iPointer = &arr[0];
    // Переместиться на третий элемент массива, используя pointer arithmetic
    *iPointer = 2;
    iPointer +=2;
    print();
    // Вписать в первый элемент массива напрямую, и в третий через iPointer, значения 5 и 6
    arr[0] = 5;
    *iPointer = 6;
    print();

    return 0;
}

using namespace std;