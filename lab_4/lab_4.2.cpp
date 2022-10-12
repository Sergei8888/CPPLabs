//
// Created by Sergei Kuzmenkov on 23.09.2022.
//

#include <iostream>

/*
 * Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
 * Упорядочить последовательность по неубыванию первой цифры числа,
 * числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию наибольшей цифры числа,
 * числа с одинаковыми первыми цифрами и одинаковыми наибольшими цифрами дополнительно упорядочить по неубыванию самого числа.
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
    int firstNumerals[n];
    int maxNumerals[n];
    for (int i = 0; i < n; i++) {
        std::cout << "Введите число последовательности: ";
        int currentNumber;
        std::cin >> currentNumber;
        series[i] = currentNumber;

        int firstNumeral = currentNumber;
        while (firstNumeral > 9) {
            firstNumeral /= 10;
        }
        firstNumerals[i] = firstNumeral;

        int maxNumeral = firstNumeral;
        while (currentNumber > 0) {
            int currentNumeral = currentNumber % 10;
            if (currentNumeral > maxNumeral) {
                maxNumeral = currentNumeral;
            }
            currentNumber /= 10;
        }
        maxNumerals[i] = maxNumeral;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (firstNumerals[i] != firstNumerals[j]) {
                if (firstNumerals[i] > firstNumerals[j]) {
                    int temp = series[i];
                    series[i] = series[j];
                    series[j] = temp;

                    temp = firstNumerals[i];
                    maxNumerals[i] = firstNumerals[j];
                    maxNumerals[j] = temp;

                    temp = maxNumerals[i];
                    maxNumerals[i] = maxNumerals[j];
                    maxNumerals[j] = temp;
                }

                continue;
            }

            if (maxNumerals[i] != maxNumerals[j]) {
                if (maxNumerals[i] > maxNumerals[j]) {
                    int temp = series[i];
                    series[i] = series[j];
                    series[j] = temp;

                    temp = firstNumerals[i];
                    maxNumerals[i] = firstNumerals[j];
                    maxNumerals[j] = temp;

                    temp = maxNumerals[i];
                    maxNumerals[i] = maxNumerals[j];
                    maxNumerals[j] = temp;
                }

                continue;
            }

            if (series[i] > series[j]) {
                int temp = series[i];
                series[i] = series[j];
                series[j] = temp;

                temp = firstNumerals[i];
                maxNumerals[i] = firstNumerals[j];
                maxNumerals[j] = temp;

                temp = maxNumerals[i];
                maxNumerals[i] = maxNumerals[j];
                maxNumerals[j] = temp;
            }
        }
    }

    printArray(series, n);

    return 0;
}