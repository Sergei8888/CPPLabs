//
// Created by Sergei Kuzmenkov on 23.09.2022.
//

/*
 * Дана последовательность целых чисел {Aj}.
 * Найти произведение чисел, лежащих на отpезке [-2,20],
 * наименьшее из таких чисел и номер этого числа в последовательности.
 */
#include <iostream>

void printAnswer(int product, int min, int minIndex) {
    std::cout << "Произведение: " << product << "\n";
    std::cout << "Минимальное: " << min << "\n";
    std::cout << "Номер минимального: " << minIndex << "\n";
}

int main() {
    setlocale(LC_ALL, "RU");

    std::cout << "Введите количество чисел в последовательности: ";
    int n;
    std::cin >> n;

    int product = 1;
    int min;
    int minIndex = 0;
    bool validFlag = false;

    for (int i = 0; i < n; i++) {
        int currentNumber;
        std::cout << "Введите число в последовательности: ";
        std::cin >> currentNumber;

        bool insideRange = (currentNumber >= -2) && (currentNumber <= 20);
        if (!insideRange) {
            continue;
        }

        validFlag = true;

        if (i == 0) {
            min = currentNumber;
        }

        product *= currentNumber;

        if (min <= currentNumber) {
            continue;
        }

        min = currentNumber;
        minIndex = i + 1;
    }

    if (!validFlag){
        std::cout << "Нет чисел в диапазоне" << std::endl;
    } else {
        printAnswer(product, min, minIndex + 1);
    }

    return 0;
}
