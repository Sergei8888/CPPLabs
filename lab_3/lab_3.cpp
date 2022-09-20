//
// Created by Sergei Kuzmenkov on 20.09.2022.
//
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

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cout << "Введите число в последовательности: ";
        std::cin >> a[i];
    }

    int product = 1;
    int min = a[0];
    int minIndex = 0;

    for (int i = 0; i < (sizeof a / sizeof(*a)); i++){
        bool insideRange = (a[i] >= -2) && (a[i] <= 20);
        if (!insideRange) {
            continue;
        }

        product *= a[i];

        if (min <= a[i]) {
            continue;
        }

        min = a[i];
        minIndex = i;
    }

    printAnswer(product, min, minIndex);
    return 0;
}