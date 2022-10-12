//
// Created by Sergei Kuzmenkov on 07.10.2022.
//

#include <iostream>

/*
 * Дана строка длиной не более 100 символов. Удалить в ней все гласные буквы.
 * */

int main() {
    char string[100];
    std::cout << "Введите строку: ";
    std::cin >> string;

    int length = strlen(string);
    for (int i = 0; i < length; i++) {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
            string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {
            for (int j = i; j < length; j++) {
                std::cout << "Change " << string[j] << " to " << string[j + 1] << std::endl;
                string[j] = string[j + 1];
            }
            length--;
            i--;
        }
    }

    std::cout << "Итоговая строка: " << string << std::endl;
}