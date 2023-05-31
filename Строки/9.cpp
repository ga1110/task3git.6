#include <iostream>
#include <string>
using namespace std;
bool check(string s, char c) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            return false;
        }
    }
    return true;
}
int main()
{
    setlocale(LC_ALL, "rus");
    string s, s1;
    char c;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (isspace(s[i]) == 0) {
            c = s[i];
            if (check(s1, c)) {
                s1 += s[i];
            }
        }
    }
    cout << s1.size() << endl;
    system("pause");
}