#include<iostream>
#include<string>
using namespace std;
int checkl(string s, int x, int y, char s1) {
	for (int i = 0; i < x; i++) {
		if (s1 == s[i]) {
			return 1;
		}
	}
	return 0;
}
int checkr(string s, int x, int y, char s1) {
	for (int i = x + 1; i < y; i++) {
		if (s1 == s[i]) {
			return 1;
		}
	}
	return 0;
}
int main() {
	int n, h, k, i, max;
	max = 0;
	char p;
	string s1, s2, s3;
	getline(cin, s1);
	for (int i = 0; i < s1.size(); i++) {
		if (isspace(s1[i]) != 0 || i != s1.size() - 1) {
			s2 += s1[i];
		}
		else {
			if (i == s1.size() - 1) {
				s2 += s1[i];
			}
			k = 0;
			for (int j = 0; j < s2.size(); j++) {
				p = s2[i];
				if (checkl(s2, i, s2.size(), p) + checkr(s2, i, s2.size(), p) == 0) {
					k++;
				}
			}
			if (k > max) {
				max = k;
				s3.erase();
				s3 += s2 + " ";
				s2.erase();

			}
			else if (k == max) {
				s3 += s2 + " ";
				s2.erase();
			}
			else {
				s2.erase();
			}
		}
	}
	cout << s3;
}



