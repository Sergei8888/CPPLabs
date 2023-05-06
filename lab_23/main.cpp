//
// Created by Sergei Kuzmenkov on 09.03.2023.
//

#include <string>
#include <iostream>
#include <catch2/catch_test_macros.hpp>

template<typename T>
class Matrix {
public:
    T **matrix;
    int rows = 0;
    int columns = 0;

    Matrix(int rows, int columns) {
        // Allocating memory
        this->matrix = new T *[rows];
        for (int i = 0; i < rows; i++) {
            this->matrix[i] = new T[columns];
        }

        // Filling with 1
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                this->matrix[i][j] = 1;

        // Saving for later iteration over array
        this->rows = rows;
        this->columns = columns;
    }

    Matrix(const Matrix &otherMatrix) {
        // Allocating memory
        this->matrix = new T *[otherMatrix.rows];
        for (int i = 0; i < otherMatrix.rows; i++) {
            this->matrix[i] = new T[otherMatrix.columns];
        }

        // Filling with values from other matrix
        for (int i = 0; i < otherMatrix.rows; i++)
            for (int j = 0; j < otherMatrix.columns; j++)
                this->matrix[i][j] = otherMatrix.matrix[i][j];

        // Saving for later iteration over array
        this->rows = otherMatrix.rows;
        this->columns = otherMatrix.columns;
    }

    Matrix<T> getMinor(int i, int j) {
        if (this->rows != this->columns) {
            throw std::invalid_argument("Matrix is not square");
        }

        if (this->rows == 1) {
            throw std::invalid_argument("Matrix is 1x1");
        }

        Matrix<T> minor(this->rows - 1, this->columns - 1);

        int minorI = 0;
        int minorJ = 0;
        for (int row = 0; row < this->rows; row++) {
            for (int column = 0; column < this->columns; column++) {
                if (row != i && column != j) {
                    minor.matrix[minorI][minorJ] = this->matrix[row][column];
                    minorJ++;
                    if (minorJ == minor.columns) {
                        minorJ = 0;
                        minorI++;
                    }
                }
            }
        }

        return minor;
    }

    T getDeterminant() {
        if (this->rows != this->columns) {
            throw std::invalid_argument("Matrix is not square");
        }

        if (this->rows == 1) {
            return this->matrix[0][0];
        }

        if (this->rows == 2) {
            return this->matrix[0][0] * this->matrix[1][1] - this->matrix[0][1] * this->matrix[1][0];
        }

        T determinant = 0;
        for (int i = 0; i < this->columns; i++) {
            determinant += this->matrix[0][i] * this->getMinor(0, i).getDeterminant() * (i % 2 == 0 ? 1 : -1);
        }

        return determinant;
    }

    friend void checkMatricesSizeEquality(const Matrix<T> &left, const Matrix<T> &right) {
        if (left.rows != right.rows || left.columns != right.columns) {
            throw std::invalid_argument("Matrices have different sizes");
        }
    }

    friend void checkMatricesMultiplicationCompatability(const Matrix<T> &left, const Matrix<T> &right) {
        if (left.columns != right.rows) {
            throw std::invalid_argument(
                    "Matrices are not compatible for multiplication (columns of the first matrix != rows of the second matrix)");
        }
    }

    Matrix<T> &operator=(Matrix<T> const &otherMatrix) {
        if (this == &otherMatrix) { return *this; }

        checkMatricesSizeEquality(*this, otherMatrix);

        for (int i = 0; i < this->rows; i++)
            for (int j = 0; j < this->columns; j++)
                this->matrix[i][j] = otherMatrix.matrix[i][j];

        return *this;
    }

    bool operator==(Matrix<T> const &otherMatrix) {
        try {
            checkMatricesSizeEquality(*this, otherMatrix);
        } catch (std::invalid_argument &e) {
            return false;
        }

        for (int i = 0; i < this->rows; i++)
            for (int j = 0; j < this->columns; j++)
                if (this->matrix[i][j] != otherMatrix.matrix[i][j]) {
                    return false;
                }

        return true;
    }

    friend Matrix<T> operator+(const Matrix<T> &left, const Matrix<T> &right) {
        checkMatricesSizeEquality(left, right);
        Matrix<T> newMatrix(left);

        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.columns; j++)
                newMatrix.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];

        return newMatrix;
    }

    friend Matrix<T> operator-(const Matrix<T> &left, const Matrix<T> &right) {
        checkMatricesSizeEquality(left, right);
        Matrix<T> newMatrix(left);

        for (int i = 0; i < left.rows; i++)
            for (int j = 0; j < left.columns; j++)
                newMatrix.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];

        return newMatrix;
    }

    Matrix<T> operator+=(const Matrix<T> &otherMatrix) {
        for (int i = 0; i < this->rows; i++)
            for (int j = 0; j < this->columns; j++)
                this->matrix[i][j] += otherMatrix.matrix[i][j];

        return *this;
    }

    friend Matrix<T> operator*(const Matrix<T> &left, const Matrix<T> &right) {
        checkMatricesMultiplicationCompatability(left, right);

        Matrix<T> newMatrix(left);

        for (int i = 0; i < left.rows; i++) {
            for (int j = 0; j < right.columns; j++) {
                newMatrix.matrix[i][j] = 0;
                for (int k = 0; k < left.columns; k++) {
                    newMatrix.matrix[i][j] += left.matrix[i][k] * right.matrix[k][j];
                }
            }
        }

        return newMatrix;
    }

    Matrix<T> operator*=(const Matrix<T> &otherMatrix) {
        Matrix<T> newMatrix(*this);

        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < otherMatrix.columns; j++) {
                newMatrix.matrix[i][j] = 0;
                for (int k = 0; k < this->columns; k++) {
                    newMatrix.matrix[i][j] += this->matrix[i][k] * otherMatrix.matrix[k][j];
                }
            }
        }

        *this = newMatrix;
        return *this;
    }

    const Matrix<T> &operator++() {
        for (int i = 0; i < this->rows; i++) {
            this->matrix[i][this->columns - 1]++;
        }
        return *this;
    }

    const Matrix<T> operator++(T) {
        Matrix<T> oldValue = *this;

        for (int i = 0; i < this->rows; i++) {
            this->matrix[i][this->columns - 1]++;
        }

        return oldValue;
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &printedMatrix) {
        for (int i = 0; i < printedMatrix.rows; i++) {
            for (int j = 0; j < printedMatrix.columns; j++) {
                os << printedMatrix.matrix[i][j] << " ";
            }
            os << std::endl;
        }

        return os;
    }

    friend std::istream &operator>>(std::istream &is, Matrix<T> &inputMatrix) {
        for (int i = 0; i < inputMatrix.rows; i++) {
            for (int j = 0; j < inputMatrix.columns; j++) {
                is >> inputMatrix.matrix[i][j];
            }
        }

        return is;
    }
};

TEST_CASE("Matrix constructor", "[Matrix]") {
    Matrix<int> matrix(2, 2);

    REQUIRE(matrix.rows == 2);
    REQUIRE(matrix.columns == 2);
}

TEST_CASE("Matrix size equality check", "[Matrix]") {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 3);

    REQUIRE_THROWS_AS(checkMatricesSizeEquality(matrix1, matrix2), std::invalid_argument);
}

TEST_CASE("Matrix equality operator", "[Matrix]") {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);

    REQUIRE(matrix1 == matrix2);
}

TEST_CASE("Matrix copy constructor", "[Matrix]") {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(matrix1);

    REQUIRE(matrix1 == matrix2);
}

TEST_CASE("Matrix assignment operator", "[Matrix]") {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);

    matrix1.matrix[0][0] = 1;
    matrix1.matrix[0][1] = 2;
    matrix1.matrix[1][0] = 3;
    matrix1.matrix[1][1] = 4;

    matrix2 = matrix1;

    REQUIRE(matrix1 == matrix2);
}

TEST_CASE("Matrix addition", "[Matrix]") {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);
    Matrix<int> matrix3(2, 2);

    matrix1.matrix[0][0] = 1;
    matrix1.matrix[0][1] = 2;
    matrix1.matrix[1][0] = 3;
    matrix1.matrix[1][1] = 4;

    matrix2.matrix[0][0] = 5;
    matrix2.matrix[0][1] = 6;
    matrix2.matrix[1][0] = 7;
    matrix2.matrix[1][1] = 8;

    matrix3.matrix[0][0] = 6;
    matrix3.matrix[0][1] = 8;
    matrix3.matrix[1][0] = 10;
    matrix3.matrix[1][1] = 12;

    Matrix<int> calculatedMatrix = matrix1 + matrix2;

    REQUIRE(calculatedMatrix == matrix3);
}

TEST_CASE("Incompatible matrices multiplying", "[Matrix]") {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(3, 3);
    Matrix<int> a = matrix1 * matrix2;

    REQUIRE(1 == 2);
}

TEST_CASE("Matrix multiplication", "[Matrix]") {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);
    Matrix<int> matrix3(2, 2);

    matrix1.matrix[0][0] = 1;
    matrix1.matrix[0][1] = 2;
    matrix1.matrix[1][0] = 3;
    matrix1.matrix[1][1] = 4;

    matrix2.matrix[0][0] = 5;
    matrix2.matrix[0][1] = 6;
    matrix2.matrix[1][0] = 7;
    matrix2.matrix[1][1] = 8;

    matrix3.matrix[0][0] = 19;
    matrix3.matrix[0][1] = 22;
    matrix3.matrix[1][0] = 43;
    matrix3.matrix[1][1] = 50;

    Matrix<int> calculatedMatrix = matrix1 * matrix2;

    REQUIRE(calculatedMatrix == matrix3);
}

TEST_CASE("Matrix multiplication assignment", "[Matrix]") {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);
    Matrix<int> matrix3(2, 2);

    matrix1.matrix[0][0] = 1;
    matrix1.matrix[0][1] = 2;
    matrix1.matrix[1][0] = 3;
    matrix1.matrix[1][1] = 4;

    matrix2.matrix[0][0] = 5;
    matrix2.matrix[0][1] = 6;
    matrix2.matrix[1][0] = 7;
    matrix2.matrix[1][1] = 8;

    matrix3.matrix[0][0] = 19;
    matrix3.matrix[0][1] = 22;
    matrix3.matrix[1][0] = 43;
    matrix3.matrix[1][1] = 50;

    matrix1 *= matrix2;

    REQUIRE(matrix1 == matrix3);
}

TEST_CASE("Matrix increment in prefix form operator", "[Matrix]") {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);

    matrix1.matrix[0][0] = 2;
    matrix1.matrix[0][1] = 2;
    matrix1.matrix[1][0] = 4;
    matrix1.matrix[1][1] = 4;

    matrix2.matrix[0][0] = 2;
    matrix2.matrix[0][1] = 3;
    matrix2.matrix[1][0] = 4;
    matrix2.matrix[1][1] = 5;

    Matrix<int> returnedMatrixValue = ++matrix1;

    REQUIRE(returnedMatrixValue == matrix2);
}

TEST_CASE("Matrix increment in postfix form operator", "[Matrix]") {
    Matrix<int> matrix1(2, 2);
    Matrix<int> matrix2(2, 2);

    matrix1.matrix[0][0] = 2;
    matrix1.matrix[0][1] = 2;
    matrix1.matrix[1][0] = 4;
    matrix1.matrix[1][1] = 4;

    Matrix<int> matrix1copy(matrix1);

    matrix2.matrix[0][0] = 2;
    matrix2.matrix[0][1] = 3;
    matrix2.matrix[1][0] = 4;
    matrix2.matrix[1][1] = 5;

    Matrix<int> returnedMatrixValue = matrix1++;


    REQUIRE(returnedMatrixValue == matrix1copy);
    REQUIRE(matrix1 == matrix2);
}

TEST_CASE("Matrix determinant", "[Matrix]") {
    Matrix<int> matrix1(2, 2);

    matrix1.matrix[0][0] = 1;
    matrix1.matrix[0][1] = 2;
    matrix1.matrix[1][0] = 3;
    matrix1.matrix[1][1] = 4;

    REQUIRE(matrix1.getDeterminant() == -2);
}

//int main() {
///*  Реализуй алгоритм:
//    Создайте матрицы А и B размерами 3*3 и матрицу C размерами 2*3, заполните их числами.
//            Проведите операции:
//    D = A + B;
//    D = D – B;
//    D += B;
//    D *= B;
//    E = A * C;
//    F = C * B;
//    Пользователь вводит с клавиатуры i,j
//    Вывести на экран A[i][j]
//    Вычислить число Z = определитель B
//    Заменить значение A[i][j] на Z
//    A++;
//    Вывести на экран А
//*/
//    Matrix<int> matrixA(3, 3);
//    Matrix<int> matrixB(3, 3);
//    Matrix<int> matrixC(2, 3);
//    Matrix<int> matrixD(3, 3);
//    Matrix<int> matrixE(3, 2);
//    Matrix<int> matrixF(2, 3);
//
//    matrixA.matrix[0][0] = 1;
//    matrixA.matrix[0][1] = 2;
//    matrixA.matrix[0][2] = 3;
//    matrixA.matrix[1][0] = 4;
//    matrixA.matrix[1][1] = 5;
//    matrixA.matrix[1][2] = 6;
//    matrixA.matrix[2][0] = 7;
//    matrixA.matrix[2][1] = 8;
//    matrixA.matrix[2][2] = 9;
//
//    matrixB.matrix[0][0] = 1;
//    matrixB.matrix[0][1] = 2;
//    matrixB.matrix[0][2] = 3;
//    matrixB.matrix[1][0] = 4;
//    matrixB.matrix[1][1] = 5;
//    matrixB.matrix[1][2] = 6;
//    matrixB.matrix[2][0] = 7;
//    matrixB.matrix[2][1] = 8;
//    matrixB.matrix[2][2] = 9;
//
//    matrixC.matrix[0][0] = 1;
//    matrixC.matrix[0][1] = 2;
//    matrixC.matrix[0][2] = 3;
//    matrixC.matrix[1][0] = 4;
//    matrixC.matrix[1][1] = 5;
//    matrixC.matrix[1][2] = 6;
//
//    matrixD = matrixA + matrixB;
//    matrixD = matrixD - matrixB;
//    matrixD += matrixB;
//    matrixD *= matrixB;
//    matrixE = matrixA * matrixC;
//    matrixF = matrixC * matrixB;
//
//    int i, j;
//    std::cout << "Enter i and j: ";
//    std::cin >> i >> j;
//    std::cout << "A[" << i << "][" << j << "] = " << matrixA.matrix[i][j] << std::endl;
//}
