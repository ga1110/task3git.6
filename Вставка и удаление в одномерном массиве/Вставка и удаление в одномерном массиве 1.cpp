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
	int* m = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "m [" << i << "] = ";
		cin >> m[i];
	}
	return m;
}
int* res(int* m, int& n) {
	for (int i = 0; i < n; i++) {
		if (m[i] < 0) {//если эл-нт под номером i < 0 
			for (int j = i; j < n; j++) { //сдвигаем эл-нт i до n 
				m[j] = m[j + 1];
			}
			n--;
			i--;
		}
	}
	return m;
}
int main()
{
	int n, x;
	cout << "n = "; cin >> n;
	int* m = create(n);
	output(m, n);
	m = res(m, n);
	output(m, n);
	system("pause");
}

