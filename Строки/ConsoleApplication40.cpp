#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
	setlocale(LC_ALL, "russian");
	int n, h, k, i, max;
	ifstream in("f:\\Задачи c++\\Строки\\text.txt");
	string s;
	if (in.is_open()) {
		cout << "23";
	}
	else {
		cout << "13";
	}
	while (in.peek() != EOF) {
		in >> s;
	}
	in.close();
	cout << s;
}



