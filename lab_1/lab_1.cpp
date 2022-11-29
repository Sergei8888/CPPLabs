//
// Created by sergei888 on 9/12/22.
//

#include <iostream>

int main() {
    int first_side;

    std::cout << "Введите первую сторону прямоугольника:\n";
    std::cin >> first_side;

    int second_side;

    std::cout << "Введите вторую сторону прямоугольника:\n";
    std::cin >> second_side;

    std::cout << "Периметр прямоугольника: " << first_side * 2 + second_side * 2;

    return 0;
}
