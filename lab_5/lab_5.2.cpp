//
// Created by Sergei Kuzmenkov on 07.10.2022.
//

/*
 * Дан файл, содержащий русский текст, размер текста не превышает 10 К байт.
 * Найти в тексте N (N ≤ 100) самых длинных слов, в которых все буквы упорядочены по алфавиту.
 * Записать найденные слова в текстовый файл в порядке не возрастания длины.
 * Все найденные слова должны быть разными.
 * Число N вводить из файла.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int realLength(wstring word) {
    int length = 0;
    for (int i = 0; i < word.length(); i++) {
        if ((int)word[i] == 208 || (int)word[i] == 209) {
            i++;
        }
        length++;
    }
    return length;
}

int main() {
    wifstream in("text.txt");
    wofstream out("result.txt");

    // reading N
    int N;
    in >> N;

    wcout << "N: " << N << endl;

    wstring words[5000];

    int word = 0;
    while (!in.eof()) {
        wstring tempWord;
        in >> tempWord;

        while (ispunct(tempWord[tempWord.length() - 1])) {
            tempWord.pop_back();
        }

        for (int i = 0; i < tempWord.length(); i++) {
            tempWord[i] = tolower(tempWord[i]);

            if((int)tempWord[i] == 208 && (int)tempWord[i + 1] >= 144 && (int)tempWord[i + 1] <= 175) {
                if ((tempWord[i + 1] + 32) > 191) {
                    tempWord[i] += 1;
                    tempWord[i + 1] -= 32;
                } else {
                    tempWord[i + 1] += 32;
                }

                i++;
            }
        }

        // is tempWord sorted by alphabet?
        bool isSorted = true;
        for (int i = 0; i < tempWord.length() - 3; i++) {
            bool isOperateSymbol = (int)tempWord[i] == 208 || (int)tempWord[i] == 209;
            if (isOperateSymbol) {
                if ((int)tempWord[i] > (int)tempWord[i + 2]) {
                    isSorted = false;
                    break;
                } else if ((int)tempWord[i] == (int)tempWord[i + 2]) {
                    if ((int)tempWord[i + 1] > (int)tempWord[i + 3]) {
                        isSorted = false;
                        break;
                    }
                }

                i++;
            } else { // if not operate symbol
                if ((int)tempWord[i] > (int)tempWord[i + 1]) {
                    isSorted = false;
                    break;
                }
            }
        }

        if (isSorted) {
            words[word] = tempWord;
            word++;
        }
    }

    // let unique words
    for (int i = 0; i < word; i++) {
        for (int j = i + 1; j < word; j++) {
            if (words[i] == words[j]) {
                words[j] = L"";
            }
        }
    }

    // sort by length
    for (int i = 0; i < word; i++) {
        for (int j = 0; j < word - i - 1; j++) {
            if (realLength(words[j]) < realLength(words[j + 1])) {
                wstring temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    // printing words
    for (int i = 0; i < N; i++) {
        if (words[i].empty()) {
            cout << "Cлов, удовлетворяющих условию задачи < N" << endl;
            break;
        }
        wcout << realLength(words[i]) << ": " << words[i] << endl;
    }

    return 0;
}