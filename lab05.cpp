#include <cassert>
#include <string>
#include <string_view>

int countOnes(std::string_view str) {
    int count = 0;
    for (char ch : str) {
        if (ch == '1') {
            count++;
        }
    }
    return count;
}


void lab05_01() {
    assert(countOnes("001100") == 2);
    assert(countOnes("000000") == 0);
    assert(countOnes("111111") == 6);
    assert(countOnes("") == 0);
    assert(countOnes("1010101") == 4);
}


std::string_view secondWord(std::string_view str) {
    char separator = ' ';

    size_t firstSpace = str.find(separator);
    if (firstSpace == std::string_view::npos) {
        return "";
    }
    size_t secondSpace = str.find(separator, firstSpace + 1);
    if (secondSpace == std::string_view::npos) {
        return str.substr(firstSpace + 1);
    }
    return str.substr(firstSpace + 1, secondSpace - firstSpace - 1);
}

void lab05_02() {
    assert(secondWord("Hello world") == "world");
    assert(secondWord("Hello my dear") == "my");
    assert(secondWord("").empty());
    assert(secondWord(" ").empty());
    assert(secondWord(" a ") == "a");
    assert(secondWord("a  ").empty());
}

int main() {
    lab05_01();
    lab05_02();
}