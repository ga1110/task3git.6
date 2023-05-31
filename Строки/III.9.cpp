#include <string>
#include <iostream>
using namespace std;
bool check(string s, string a, string b) {
	if (s[0] == a[0]) {
		if (s[s.size() - 1] == b[0]) {
			return true;
		}
	}
	return false;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string s, b, a, t1, t2, answer;
	cout << "Введите строку: ";
	getline(cin, s);
    cout << "Введите начальный символ: ";
	cin >> t1;
	cout << "Введите конечный символ: ";
	cin >> t2;
	for (int i = 0; i < s.size(); i++) {
		if (ispunct(s[i]) || isspace(s[i])) {
			if (check(a, t1, t2)) {
				answer += a + "\n";
				a.erase();
			}
			a.erase();
		}
		else {
			a += s[i];
		}
	}
	cout << endl;
	cout << answer;
}