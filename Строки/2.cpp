#include<iostream>
#include<string>
using namespace std;

int main() {
	string s, s1, s2;
	int i, maxs;
	maxs = 0;
	getline(cin, s);
	if (ispunct(s[s.size()]) == 0 && ispunct(s[s.size()]) == 0) {
		s += " ";
	}
	for (i = 0; i < s.size(); i++) {
		if (isspace(s[i]) == 0 && ispunct(s[i]) == 0) {
			s1 += s[i];
		}
		else {
			if (s1.size() > maxs) {
				maxs = s1.size();
				s2 = s1 + " ";
				s1.erase();
			}
			else if (s1.size() == maxs) {
				s2 += s1 + " ";
				s1.erase();

			}
			else {
				s1.erase();
			}
		}
	}
	cout << s2 << endl;
	system("pause");
}

// . H
// 16 0 0 ispunct
// 0 0 257 isalpha
// 0 8 0 isspace

