#include <cassert>
#include <iostream>
#include <span>

using namespace std;

void lab04_01() {
    int number = 10;
    std::cin >> number;

    if (number % 2 == 1) {
        std::cout << "The number is not divisible by 2" << std::endl;

        if (number == 5) {
            std::cout << "The number is 5" << std::endl;
        }

        return;
    }

    std::cout << "The number is divisible by 2" << std::endl;
    if (number == 6) {
        std::cout << "The number is 6" << std::endl;
    }
}

struct FruitCounts {
    int apples;
    int pears;
    int oranges;
};


void lab04_02() {
    FruitCounts fruit_counts;

    std::cout << "Apples:";
    std::cin >> fruit_counts.apples;

    std::cout << std::endl << "Pears:";
    std::cin >> fruit_counts.pears;

    std::cout << endl << "Oranges:";
    std::cin >> fruit_counts.oranges;

    bool appleCheck = fruit_counts.apples > 5;
    bool pearCheck = fruit_counts.pears < 8;
    bool orangeCheck = fruit_counts.apples * 2 == fruit_counts.oranges;

    if (appleCheck && pearCheck && orangeCheck) {
        cout << endl << "Hello" << endl;
    }
}

void product(std::span<int> inputOutput, std::span<int> coefficients) {
    assert(inputOutput.size() == coefficients.size());

    // for (size_t i = 0; i < inputOutput.size(); i++) {
    //     inputOutput[i] *= coefficients[i];
    // }
    //
    for (int &i: inputOutput) {
        i *= coefficients[&i - &inputOutput[0]];
    }
    //
    // for (size_t i = 0;; i++) {
    //     if (i >= inputOutput.size()) break;
    //     inputOutput[i] *= coefficients[i];
    // }

    // size_t i = 0;
    // while (i < inputOutput.size()) {
    //     inputOutput[i] *= coefficients[i];
    //     i++;
    // }

    return;
}

void lab04_03() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {2, 3, 4};

    span<int> span1(arr1, 3);
    span<int> span2(arr2, 3);

    product(span1, span2);

    for (int i: span1) {
        cout << i << " ";
    }

    return;
}

int main() {
    lab04_01();
    lab04_02();
    lab04_03();
}

