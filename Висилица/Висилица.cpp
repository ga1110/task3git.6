#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <windows.h>
using namespace std;
vector<char> alphabet = { 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' };
vector<char> word_orig;
vector<char> word_game;
string word_str;
string letter;
int miss = 0;
int w_o, w_g;
void str_to_vector(string word) {
    for (int i = 0; i < word.size(); i++) {
        word_orig.push_back(word[i]);
        word_game.push_back('-');
    }
}
bool alp_del(char a) {
    if (a == letter[0]) {
        return true;
    }
    return false;

}
void game_w(string letter) {
    if (word_str == letter) {
        for (int i = 0; i != word_orig.size(); i++) {
            if (word_game[i] == '-') {
                swap(word_orig[i], word_game[i]);
            }
            
        }
    }
    else {
        miss++;
    }
}
void game_l(string letter) {
    int i = 0;
    int j = 0;
    vector<char>::iterator it = remove_if(alphabet.begin(), alphabet.end(), alp_del);
    alphabet.erase(it, alphabet.end());
    while (i < word_orig.size()) {
        if (word_orig[i] == letter[0]) {
            swap(word_orig[i], word_game[i]);
        }
        else {
            j++;
        }
        i++;
    }
    if (j == word_orig.size()) {
        miss++;
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    cout << "Введите слово: "; getline(cin, word_str);
    system("cls");
    str_to_vector(word_str);
    while ((count(word_game.begin(), word_game.end(), '-') != 0) && (miss != 7)) {
        for (vector<char>::iterator it = word_game.begin(); it != word_game.end(); it++) {
            cout << *it << " ";
        }
        cout << "Ошибок: "; cout << miss; cout << " (максимум 7)";
        cout << "\n";
        cout << "Оставшиеся буквы: ";
        for (vector<char>::iterator it = alphabet.begin(); it != alphabet.end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
        cout << "Введите букву или слово: ";
        getline(cin, letter);
        if (letter.size() == 1) {
            game_l(letter);
        }
        else {
            game_w(letter);
        }
        
    }
    cout << "Ответ: ";
    for (vector<char>::iterator it = word_game.begin(); it != word_game.end(); it++) {
        cout << *it;
    }
    cout << endl;
    if ((count(word_game.begin(), word_game.end(), '-') == 0)) {
        cout << "Вы победили и совершили " << miss << " ошибок!" << endl;
    }
    else {
        cout << "Вы проиграли." << endl;
    }
    cout << endl;
    system("pause");
}
