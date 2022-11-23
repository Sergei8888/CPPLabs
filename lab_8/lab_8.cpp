//
// Created by Sergei Kuzmenkov on 23.11.2022.
//

/*
 * Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
 * Упорядочить последовательность по неубыванию первой цифры числа,
 * числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию наибольшей цифры числа,
 * числа с одинаковыми первыми цифрами и одинаковыми наибольшими цифрами дополнительно упорядочить по неубыванию самого числа.
 * */

#include <iostream>

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

int getFirstNumeral(int number) {
    while (number > 9) {
        number /= 10;
    }
    return number;
}

int getMaxNumeral(int number) {
    int maxNumeral = 0;
    while (number > 0) {
        int numeral = number % 10;
        if (numeral > maxNumeral) {
            maxNumeral = numeral;
        }
        number /= 10;
    }
    return maxNumeral;
}

int main() {
    std::cout << "Введите длинну последовательности: ";
    int n = *new int;
    std::cin >> n;

    // Arrays
    int *series = new int[n];
    int *firstNumerals = new int[n];
    int *maxNumerals = new int[n];

    for (int i = 0; i < n; i++) {
        // Getting number from the console
        std::cout << "Введите число последовательности: ";
        std::cin >> series[i];

        firstNumerals[i] = getFirstNumeral(series[i]);
        maxNumerals[i] = getMaxNumeral(series[i]);
    }

    std::cout << "Исходная последовательность: ";
    printArray(series, n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Sorting by first numeral
            if (firstNumerals[i] != firstNumerals[j]) {
                if (firstNumerals[i] > firstNumerals[j]) {
                    std::swap(series[i], series[j]);
                    std::swap(firstNumerals[i], firstNumerals[j]);
                    std::swap(maxNumerals[i], maxNumerals[j]);
                }

                continue;
            }

            // Sorting by max numeral
            if (maxNumerals[i] != maxNumerals[j]) {
                if (maxNumerals[i] > maxNumerals[j]) {
                    std::swap(series[i], series[j]);
                    std::swap(firstNumerals[i], firstNumerals[j]);
                    std::swap(maxNumerals[i], maxNumerals[j]);
                }

                continue;
            }

            // Sorting by number
            if (series[i] > series[j]) {
                std::swap(series[i], series[j]);
                std::swap(firstNumerals[i], firstNumerals[j]);
                std::swap(maxNumerals[i], maxNumerals[j]);
            }
        }
    }

    std::cout << "Отсортированная последовательность: ";
    printArray(series, n);

    std::cout << "Введите новую длинну последовательности: ";
    int newN = *new int;
    std::cin >> newN;

    if (newN <= n) {
        std::cout << "Новая последовательность: .\n";
        printArray(series, newN);
    } else {
        int *newSeries = new int[newN];

        // Copying old series
        for (int i = 0; i < n; i++) {
            newSeries[i] = series[i];
        }
        // Adding new numbers
        for (int i = n; i < newN; i++) {
            std::cout << "Введите недостающее значение последовательности: ";
            std::cin >> newSeries[i];
        }

        std::cout << "Новая последовательность: \n";
        printArray(newSeries, newN);
    }

    return 0;
}