#include <iostream>

using namespace std;

//int hello(int i);

// В финальном исполняемом файле будет только одна копия функции hello
static int hello(int i) {
    return i + 4;
}

// 6. Если компилировать без f.cpp, то будет ошибка компиляции
int main() {
    cout << hello(1) << endl;
}