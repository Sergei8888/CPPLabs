//
// Created by Sergei Kuzmenkov on 30.09.2022.
//

#include "string.h"
#include <iostream>

/*
 * Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100).
 * Найти столбец содержащий наименьший элемент матрицы и заменить все отрицательные элементы этого столбца числом 0.
 * */

int main() {
    std::cout << "Введите количество строк матрицы: ";
    int rows;
    std::cin >> rows;

    std::cout << "Введите количество столбцов матрицы: ";
    int columns;
    std::cin >> columns;

    int matrix[rows][columns];
    int minElement = INT32_MAX;
    int minElementColumn = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int element;
            std::cout << "Введите элемент матрицы [" << i << "][" << j << "]: ";
            std::cin >> element;
            matrix[i][j] = element;

            if (element < minElement) {
                minElement = element;
                minElementColumn = j;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Миниммальный элемент матрицы: " << minElement << std::endl;
    std::cout << "Столбец с минимальным элементом матрицы: " << minElementColumn + 1 << std::endl;

    for (int i = 0; i < rows; ++i) {
        if (matrix[i][minElementColumn] < 0) {
            matrix[i][minElementColumn] = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}