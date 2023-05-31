#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main() {
	int n, h, k, i, max;
	string s;
	ifstream in("text.txt");
	if (!in.is_open()) {
		cout << "Ошибка открытия файла"
	}
	else {
		cout << "Ошибка открытия файла"
	}
	while (in.peek() != EOF) {
		in >> s;
	}
	in.close();
	cout << s;
}



