#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    //string s, s1, s2,ans;
    ifstream in("F:\\Задачи c++\\Строки\\text.txt");
    getline(in, s);
    in.close();
    string m[12] = { "january", "february", "march", "april", "may", "june", "july","august","september","october","november","december" };
    for (int i = 0; i < s.size(); i++) {
        if ((ispunct(s[i]) != 0 && isspace(s[i + 1]) != 0 && isalpha(s[i + 2]) != 0) || (ispunct(s[i]) != 0 && isalpha(s[i + 2]) != 0) || (i == s.size() - 1)) {
            if (i == s.size() - 1 && isspace(s[i]) == 0) {
                s2 += s[i];
            }
            s1 += s2;
            for (int j = 0; j < s1.size() - 14; j++) {
                if (isdigit(s1[j]) != 0 && isdigit(s1[j + 1]) != 0 && ispunct(s1[j + 2]) != 0 && isdigit(s1[j + 3]) != 0 && isdigit(s1[j + 4]) != 0 && ispunct(s1[j + 5]) != 0 && isdigit(s1[j + 6]) != 0 && isdigit(s1[j + 7]) != 0 && isdigit(s1[j + 8]) != 0 && isdigit(s1[j + 9]) != 0) {
                    ans += s1 + " ";
                }
            }
            s1.erase();
            s2.erase();
        }
        else {
            s2 += s[i];
        }
    }
    //cout << s << endl;
    //cout << s2 << endl;
    //cout << s1;
    //cout << ans;
}
