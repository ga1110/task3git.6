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
	cout << "\n";
	return m;
}
int search_max(int* m, int n) { //ищем максимальный элемент
	int a = m[0];
	for (int i = 0; i < n; i++) {
		if (a < m[i]) {
			a = m[i];
		}
	}
	cout << "Max = " << a << "\n";
	return a;
}
int* res(int* m, int& n, int max, int x) {
	for (int i = 0; i < n; i++) {
		if (m[i] == max) {
			n++;
			for (int j = n; j > i - 1; j--) { //сдвигаем элементы вправо
				m[j] = m[j - 1];
			}
			m[i] = x; //ставим x на предыдущее место элемента x
			i++;

		}
	}
	return m;
}
int main()
{
	int n, max, x;
	cout << "n = "; cin >> n;
	cout << "X = "; cin >> x;
	int* m = create(n);
	output(m, n);
	max = search_max(m, n);
	m = res(m, n, max, x);
	output(m, n);
}

