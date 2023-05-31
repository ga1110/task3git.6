#include <iostream>
#include<string>
using namespace std;

int main() {
	string s1, s2;
	char max;
	getline(cin, s1);
	cout << "string = " << s1 << endl;
	for (int i = 0; i < s1.size(); i++) {
		if (isalpha(s1[i]) == 0 && isspace(s1[i]) == 0) {
			if (s1[i] % 2 == 0) {
				s2 += s1[i];
			}
		}
	}
	max = s2[0];
	for (int i = 0; i < s2.size(); i++) {
		if (max < s2[i]) {
			max = s2[i];
		}
	}
	cout << "Max = " << max;
	system("pause");
	return 0;
}
