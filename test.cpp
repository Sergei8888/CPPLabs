//
// Created by Sergei Kuzmenkov on 07.10.2022.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");

    wifstream in("test.txt");

    while (!in.eof()) {
        wstring tempWord;
        in >> tempWord;

        for (int i = 0; i < tempWord.length(); i += 2) {
            wcout << (int)tempWord[i] << " : " << (int)tempWord[i + 1] << endl;
        }

        wcout << tempWord << endl;
    }

    return 0;
}
