#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int check(string* m, string s, int j, int &k) {
    string h;
    h.append(s, j, j + 10);
    for (int i = 0; i < 12; i++) {
        if (h.find(m[i]) <= h.size() && h.find(m[i]) >= 0) {
            k = h.find_last_of(m[i]);
            return 1;
        }
    }
    return 0;
}
int main()
{
    int k;
    k = 0;
    string s, s1, s2, ans;
    ifstream in("F:\\Задачи c++\\Строки\\text.txt");
    getline(in, s);
    in.close();
    string m[12] = { "january", "february", "march", "april", "may", "june", "july","august","september","october","november","december" };
    for (int i = 0; i < s.size(); i++) {
        if ((ispunct(s[i]) != 0 && isspace(s[i + 1]) != 0 && isalpha(s[i + 2]) != 0) || (ispunct(s[i]) != 0 && isalpha(s[i + 2]) != 0) || (i == s.size() - 1)) {
            if (i == s.size() - 1 && isspace(s[i]) == 0) {
                s2 += s[i];
            }
            for (int j = 0; j < s2.size() - 9; j++) {
                if ((isdigit(s2[j]) != 0 && isdigit(s2[j + 1]) != 0 && ispunct(s2[j + 2]) != 0 && isdigit(s2[j + 3]) != 0 && isdigit(s2[j + 4]) != 0 && ispunct(s2[j + 5]) != 0 && isdigit(s2[j + 6]) != 0 &&
                    isdigit(s2[j + 7]) != 0 && isdigit(s2[j + 8]) != 0 && isdigit(s2[j + 9]) != 0) || (isdigit(s2[j]) != 0 && isdigit(s2[j + 1]) != 0 && isspace(s2[j + 2]) != 0 && check(m, s2, j+2,k) == 1)
                    && isspace(s2[j+2+k] != 0 && isdigit(s2[j + 3+ k]) != 0 && isdigit(s2[j + 4 + k]) != 0 && isdigit(s2[j + 5 + k]) != 0 && isdigit(s2[j + 6 + k]) != 0)) {
                    ans += s2 + " ";
                    break;
                }
            }
            s2.erase();
        }
        else {
            s2 += s[i];
        }
    }
    //cout << s << endl;
    //cout << s2 << endl;
    //cout << s1;
    // 
    cout << ans;
    system("pause");
}