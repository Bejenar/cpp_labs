// Если будет только сигнатура, то будет ошибка компиляции
// int hello(int i);

// Теперь будет работать
//int hello(int i) {
//    return i + 3;
//}

// Игнорируется линкером
static int hello(int i) {
    return i + 3;
}