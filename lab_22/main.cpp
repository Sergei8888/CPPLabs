//
// Created by Sergei Kuzmenkov on 09.03.2023.
// Реализуйте класс R_Complex для работы с комплексными числами в формате (r, angle). Он должен включать:
//
// Базовый конструктор
// Конструктор копирования
// Оператор присваивания копированием
// Деструктор
// Операторы += и +, *= и *
// Оператор ++ префиксный и постфиксный (увеличение модуля числа на 1)
// Операторы ввода и вывода
//
#include <iostream>
#include <cmath>

class R_Complex {
private:
    double r;
    double angle;
public:
    R_Complex() {
        this->r = 0;
        this->angle = 0;
    }

    R_Complex(double r, double angle) {
        this->r = r;
        this->angle = std::fmod(angle, 360);
    }

    R_Complex(const R_Complex &otherNumber) {
        this->r = otherNumber.r;
        this->angle = otherNumber.angle;
    }

    double GetR() const {
        return this->r;
    }

    double GetAngle() const {
        return this->angle;
    }

    R_Complex &operator+=(const R_Complex &number) {
        this->r += std::sqrt(this->r * this->r + number.r * number.r);
        this->angle = std::fmod((this->angle + number.angle) / 2, 360);

        return *this;
    }

    friend R_Complex operator+(const R_Complex &left, const R_Complex &right) {
        double resultR = std::sqrt(left.r * left.r + right.r * right.r);
        double resultAngle = (left.angle + right.angle) / 2;

        return {resultR, std::fmod(resultAngle, 360)};
    }

    friend R_Complex operator*(const R_Complex &left, const R_Complex &right) {
        double resultR = left.r * right.r;
        double resultAngle = left.angle + right.angle;
        return {resultR, std::fmod(resultAngle, 360)};
    }

    R_Complex &operator*=(const R_Complex &number) {
        this->r = std::sqrt(this->r * this->r + number.r * number.r);
        this->angle = std::fmod(((this->angle + number.angle) / 2), 180);
        return *this;
    }

    const R_Complex &operator++() {
        this->r++;
        return *this;
    }

    const R_Complex operator++(int) {
        R_Complex oldValue = *this;
        this->r++;
        return oldValue;
    }

    friend std::ostream &operator<<(std::ostream &os, const R_Complex &number) {
        return os << "Complex number: ";
    }
};

int main() {
    R_Complex complexNumber2(5, 360);

    int i = 0;
    std::cout << "Post" << std::endl;
    while (i < 10) {
        std::cout << complexNumber2++ << std::endl;
        i++;
    }

    i = 0;
    std::cout << "Prefix" << std::endl;
    while (i < 10) {
        std::cout << ++complexNumber2 << std::endl;
        i++;
    }

    return 0;
}