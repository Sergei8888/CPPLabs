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

int getMaxNumeral(int i) {
    int max = 0;
    while (i > 0) {
        int numeral = i % 10;
        if (numeral > max) {
            max = numeral;
        }
        i /= 10;
    }
    return max;
}

int getFirstNumeral(int i) {
    while (i > 9) {
        i /= 10;
    }
    return i;
}

bool compare(int i, int j) {
    if (getFirstNumeral(i) != getFirstNumeral(j)) {
        return getFirstNumeral(i) < getFirstNumeral(j);
    }

    if (getMaxNumeral(i) != getMaxNumeral(j)) {
        return getMaxNumeral(i) < getMaxNumeral(j);
    }

    return i < j;
}


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
    for (int i = 0; i < n; i++) {
        std::cout << "Введите число последовательности: ";
        std::cin >> series[i];
    }

    std::sort(series, series + n, compare);
    printArray(series, n);

    return 0;
}