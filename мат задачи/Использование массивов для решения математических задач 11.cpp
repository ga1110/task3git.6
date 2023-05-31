#include<iostream>
using namespace std;
int** output_res(int n, int** a) { // вывод результата 
	for (int j = 0; j < n + 1; j++) {
		cout << a[n][j] << " ";
	}
	return 0;
}
int** create(int** a, int n) { // создание двумерного массива
	for (int i = 0; i < n + 1; i++)
		a[i] = new int[i];
	return a;
}
int check(int i, int j) { // проверка эл-та a[i][j] 
	if (i == 0 || i == 1 || j == i || j == 0) return 1;
	else return 0;
}

int main() {
	int n, j, i;
	cout << "n = "; cin >> n;
	int** a = new int* [n + 1];
	a = create(a, n);
	for (i = 0; i < n + 1; i++) {
		for (j = 0; j < i + 1; j++) {
			if (check(i, j))  a[i][j] = 1; //нулевая и первая строки состоят из 1 
			else a[i][j] = a[i - 1][j - 1] + a[i - 1][j]; // эл-нт a[i][j] = прошлый элемент с прошлой строки + эл-нт под таким же номером но с предыдущей строки 
		}
	}
	output_res(n, a);
}