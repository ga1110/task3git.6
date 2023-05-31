#include <iostream>
#include<string>
using namespace std;

int main() {
	string s1 = "a12-3bc";
	const char* s2 = s1.c_str();
	int k = s1.size();
	string s3;
	for (int i = 0; i < k; i++) {
		if (isdigit(s2[i])!=0) {
			s3.push_back(s1[i]);
			s3.push_back(' ');
		}
	}
	const char* s4 = s3.c_str();
	int z = atoi(s4);
	cout << z;

	return 0;
}
