#include <iostream>
#include <string>
using namespace std;
int sum_func(int sign, string s) {
    const char* c = s.c_str();
    int x = atoi(c);
    return x * (sign);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int sum = 0;
    int j = 0;
    string s;
    string s1;
    int sign = 1;
    cout << "Введите строку: ";
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            sign = -1;
        }
        if (s[i] == '+') {
            sign = 1;
        }
        if ((isspace(s[i])) || i == s.size() - 1) {
            for (j; j < i + 1; j++) {
                if (isdigit(s[j]) != 0) {
                    s1 += s[j];
                }
            }
            j = i;
            if (s1.size() != 0) {
                sum += sum_func(sign, s1);
            }

            s1.erase();

        }
    }
    cout << sum << endl;
    system("pause");
}