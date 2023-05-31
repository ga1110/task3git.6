#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    ifstream fin("C:\\Users\\Home\\Downloads\\txt.txt");
    string numbers = "1234567890";
    string word, first_num;
    int i = 0;
    int j = 0;
    getline(fin, str);
    //cout <<str.find_first_of(numbers,5)<< endl;
    map<string, int> let, num;
    while (i < str.size()) {
        for (j = i; j < min(str.find_first_of(" ", i), str.size()); j++) {
            word += str[j];
        }
        i = j + 1;
        if ((word.find_first_of(numbers) > word.size()) || (word.find_first_of(numbers) < 0)) {
            let[word]++;
            word.erase();
        }
        else {
            if (num.size() == 0) {
                first_num = word;
            }
            num[word]++;
            word.erase();
        }
    }
    map<string, int>::iterator it_first_num;
    for (it_first_num = num.begin(); it_first_num != num.end(); it_first_num++) {
        if ((*it_first_num).first == first_num) {
            break;
         }
    }
    for (map<string, int>::iterator it_let = let.begin(); it_let != let.end(); it_let++) {
        if ((*it_let).second == (*it_first_num).second) {
            cout << (*it_let).first << endl;
        }

    }
    system("pause");
}
