#include <iostream>
using namespace std;
int* output(int* m, int n) { //вывод массива
	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}
	cout << "\n";
	return 0;
}
int* create(int n) { //создание массива
	int* m = new int[2 * n];
	for (int i = 0; i < n; i++) {
		cout << "m [" << i << "] = "; cin >> m[i];
	}
	return m;
}
int found_min(int* m, int n) { //ищем минимальный эл-нт
	int a = m[0];
	for (int i = 0; i < n; i++) {
		if (a > m[i]) {
			a = m[i];
		}
	}
	cout << "Min = " << a << "\n";
	return a;
}
int* res(int* m, int& n, int min, int x) {
	for (int i = 0; i < n; i++) {
		if (m[i] == min) {
			n++;
			for (int j = n; j > i; j--) { //сдвигаем элементы вправо
				m[j] = m[j - 1];
			}
			m[i + 1] = x; //ставим x перед элемениом i
			i++;

		}
	}
	return m;
}
int main()
{
	int n, min, x;
	cout << "n = "; cin >> n;
	cout << "X = "; cin >> x;
	int* m = create(n);
	output(m, n);
	min = found_min(m, n);
	m = res(m, n, min, x);
	output(m, n);
}

for (int i = 0; i < n; i++) {
	if (check(m, i, h) == 0) {

		n++;
		for (int j = n; j > i; j--) {
			for (int t = 0; t < h; t++) {
				m[j][t] = m[j - 1][t];
			}

		}
		for (int u = 0; u < h; u++) {
			m[i + 1][u] = 0;
		}
		i += 2;
}