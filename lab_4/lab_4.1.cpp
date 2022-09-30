//
// Created by Sergei Kuzmenkov on 23.09.2022.
//

#include <iostream>
#include <algorithm>

/*
 * Дана последовательность натуральных чисел {aj}j=1...n (n<=10000).
 * Если в последовательности есть хотя бы одно число, сумма цифр которого равна 14, упорядочить последовательность по неубыванию.
 * */

void printArray(int series[], int length) {
    std::cout << "[";

    for (int i = 0; i < length; i++) {
        std::cout << series[i];
        if (i + 1 < length) {
            std::cout << " ";
        }
    }

    std::cout << "]\n";
}

int getNumeralsSum(int number) {
    int numeralsSum = 0;
    while (number > 0) {
        numeralsSum += number % 10;
        number /= 10;
    }
    std::cout << "Сумма цифр: " << numeralsSum << std::endl;

    return numeralsSum;
}

int main() {
    std::cout << "Введите длинну последовательности: ";
    int n;
    std::cin >> n;

    int series[n];
    bool numeralsSumEqualsFlag = false;
    for (int i = 0; i < n; i++) {
        std::cout << "Введите число последовательности: ";
        int currentNumber;
        std::cin >> currentNumber;
        series[i] = currentNumber;

        if (getNumeralsSum(currentNumber) == 14) {
            numeralsSumEqualsFlag = true;
        }
    }

    if (!numeralsSumEqualsFlag) {
        printArray(series, n);
        return 0;
    }

    std::cout << "Сортированная последовательность: ";
    std::sort(series,series + n);
    printArray(series, n);
    return 0;
}
