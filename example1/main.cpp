#include <iostream>

using namespace std;

int hello(int i);

int main() {
    cout << hello(1) << endl;
}

// Без этих строчек компилятор выдаст ошибку
int hello(int i) {
    return i + 1;
}

