#include <iostream>
#include<string>
using namespace std;

int main() {
	string s1 = "a";
	const char* s2 = s1.c_str();
	int k = s1.size();
	string s3;
	for (int i = 0; i < k; i++) {
		if (isalpha(s2[i]) == 0 && isspace(s2[i]) == 0) {
			s3.push_back(s1[i]);
		}
	}
	int k = atoi(s1);
	cout >> k;
	return 0;
}
