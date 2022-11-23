//
// Created by Sergei Kuzmenkov on 21.10.2022.
//

/**
 * Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100.
 * Если в матрице есть две одинаковых строки, заменить минимальные элементы столбцов на наибольший из простых элементов матрицы.
 */

#include <iostream>

using namespace std;

void getMatrix(int matrix[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Введите элемнт матрицы A[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPrime(int number) {
    if (number == 1) return false;
    if (number == 2) return true;

    for (int i = 2; i < number; i++) {
        if (number % i == 0) return false;
    }

    return true;
}

int overloaded(int a, int b) {
    return a + b;
}

bool overloaded(bool a, bool b) {
    return a || b;
}

int byValue(int a) {
    a += 1;
    cout << "a = " << a << endl;
    return a;
}

int byPointer(int& a) {
    a += 1;
    cout << "a = " << a << endl;
    return a;
}

int main() {
    cout << "Введите размер матрицы A: ";
    int n;
    cin >> n;

    int matrix[100][100];
    getMatrix(matrix, n);

    int minInColumn[100] = {0};
    int maxInColumn[100] = {0};
    for (int i = 0; i < n; i++) {
        minInColumn[i] = matrix[0][i];
        maxInColumn[i] = matrix[0][i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < minInColumn[j]) {
                minInColumn[j] = matrix[i][j];
            }

            if (matrix[i][j] > maxInColumn[j]) {
                maxInColumn[j] = matrix[i][j];
            }
        }
    }

    int maxPrime = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(matrix[i][j])) {
                if (matrix[i][j] > maxPrime) {
                    maxPrime = matrix[i][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == minInColumn[j]) {
                matrix[i][j] = maxPrime;
            }
        }
    }

    printMatrix(matrix, n);

    cout << overloaded(1, 2) << endl;
    cout << overloaded(true, false) << endl;

    int a = 1;
    byValue(a);
    cout << "By value: " << a << endl;
    byPointer(a);
    cout << "By pointer: " << a << endl;

    return 0;
}