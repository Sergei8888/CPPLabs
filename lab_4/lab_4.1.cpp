//
// Created by Sergei Kuzmenkov on 23.09.2022.
//

#include <iostream>

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

        int numeralsSum = 0;
        while (currentNumber > 0) {
            numeralsSum += currentNumber % 10;
            currentNumber /= 10;
        }
        std::cout << "Сумма цифр: " << numeralsSum << std::endl;

        if (numeralsSum == 14) {
            numeralsSumEqualsFlag = true;
        }
    }

    if (!numeralsSumEqualsFlag) {
        printArray(series, n);
        return 0;
    }

    std::cout << "Сортированная последовательность: ";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (series[j] > series[j + 1]) {
                int temp = series[j];
                series[j] = series[j + 1];
                series[j + 1] = temp;
            }
        }
    }

    printArray(series, n);
    return 0;
}
