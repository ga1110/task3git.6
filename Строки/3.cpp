#include<iostream>
#include<string>
using namespace std;
int checkl(string s1, char c) {
	int t = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == c) {
			return 1;
		}
	}
	return 0;
}
int main() {
	int n, h, k, i, max;
	max = 0;
	char p;
	string s1, s2, s3, s4;
	getline(cin, s1);
	if (ispunct(s1[s1.size()]) == 0 && ispunct(s1[s1.size()]) == 0) {
		s1 += " ";
	}
	for (int j = 0; j < s1.size(); j++) {
		if (isspace(s1[j]) == 0 && ispunct(s1[j]) == 0) {
			s2 += s1[j];
		}
		else {
			for (int i = 0; i < s2.size(); i++) {
				if (checkl(s3, s2[i]) == 0) {
					s3 += s2[i];
				}
			}
			if (max < s3.size()) {
				max = s3.size();
				s4.erase();
				s4 += s2 + " ";
				s3.erase();
				s2.erase();

			}
			else if (max == s3.size()) {
				s4 += s2 + " ";
				s3.erase();
				s2.erase();
			}
			else {
				s3.erase();
				s2.erase();
			}
		}
	}

	cout << s4 << " " << max << endl;
	system("pause");
}



