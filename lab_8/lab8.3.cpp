//
// Created by Sergei Kuzmenkov on 09.12.2022.
//
#include <iostream>

/*
 * Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100).
 * Найти столбец содержащий наименьший элемент матрицы и заменить все отрицательные элементы этого столбца числом 0.
 * */

int main() {
    std::cout << "Введите количество строк матрицы: ";
    int *rows = new int;
    std::cin >> *rows;

    std::cout << "Введите количество столбцов матрицы: ";
    int *columns = new int;
    std::cin >> *columns;

    int **matrix = new int *[*rows];
    for (int i = 0; i < *rows; i++) {
        matrix[i] = new int[*columns];
    }

    int *minElement = new int;
    *minElement = INT32_MAX;

    int *minElementColumn = new int;
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *columns; j++) {
            int *element = new int;
            std::cout << "Введите элемент матрицы [" << i << "][" << j << "]: ";
            std::cin >> *element;
            matrix[i][j] = *element;

            if (*element < *minElement) {
                *minElement = *element;
                *minElementColumn = j;
            }
        }
    }

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Миниммальный элемент матрицы: " << *minElement << std::endl;
    std::cout << "Столбец с минимальным элементом матрицы: " << *minElementColumn + 1 << std::endl;

    for (int i = 0; i < *rows; ++i) {
        if (matrix[i][*minElementColumn] < 0) {
            matrix[i][*minElementColumn] = 0;
        }
    }

    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *columns; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    for (int i = 0; i < *rows; i++) {
        delete matrix[i];
    }

    delete[] matrix;


    return 0;
}