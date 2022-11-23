//
// Created by Sergei Kuzmenkov on 23.10.2022.
//

/*#include <iostream>


using namespace std;
int main(){
    char str[100];
    char glas[7] = "aioyeu";
    cin >> str;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'u' || str[i] == 'y' || str[i] == 'o'){


            for(int j=0;j<strlen(glas);j++)
                if (str[i] == glas[j]){
                    str[i] -= 32;
                }
            }
    std::cout << str;

}
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(){
    setlocale(LC_ALL,"ru");

    string path = "index.txt";

    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open()) {
        cout << "ошибка открытия файла" << endl;
    } else {
        int value ;
        string msg;
        cout << "файл откртыт" << endl;

        cout << "Нажмите 1 для записи текста в файл:" << endl;
        cout << "Нажмите 2 для вывода всез записей из файла: " << endl;
        cin >> value;

        if (value == 1) {
            cin >> msg;
            fs << msg << "\n";
        }
        if (value == 2) {

        }

    }
    fs.close();

    return 0;

}