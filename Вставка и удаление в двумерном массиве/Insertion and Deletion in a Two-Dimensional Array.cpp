#include <iostream>
using namespace std;
int** create(int n, int h) { // функция создания и ввода двумерного массива 
    int** m = new int* [2 * n + 1];
    for (int i = 0; i < 2 * n + 1; i++) {
        m[i] = new int[2 * n + 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            cout << "Введите элемент " << "[" << i << "][" << j << "]  ";
            cin >> m[i][j];
        }
    }
    cout << "\n";
    return m;
}
int* create_x(int n) { // функция создания и вывода строки X
    int* m = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "x [" << i << "] = "; cin >> m[i];
    }
    cout << "\n";
    cout << "X = (";
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            cout << m[i] << " ";
        }
        else {
            cout << m[i];
        }
    }
    cout << ")";
    cout << "\n";
    return m;
}
int output(int** m, int n, int h) {// функция вывода
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}
int check(int** m, int i, int h) {// функция проверки строки 
    for (int j = 0; j < h; j++) {
        if (m[i][j] < 0) {
            return 1;
        }
    }
    return 0;
}
int** res(int** m, int* x, int& n, int h) {// функция решения 
    for (int i = 0; i < n; i++) {
        if (check(m, i, h) == 0) {// если строка содержит только положительные элементы 
            n++;
            for (int j = n; j > i; j--) {//добавляем строку x после строки i
                for (int t = 0; t < h; t++) {
                    m[j][t] = m[j - 1][t];
                }

            }
            for (int u = 0; u < h; u++) {
                m[i + 1][u] = x[u];
            }
            i += 1;
        }
    }
    return m;
}
int main()
{
    setlocale(LC_ALL, "rus");
    int n, h;
    cout << "n = "; cin >> n;
    cout << "h = "; cin >> h;
    int* x = create_x(h);
    int** m = create(n, h);
    output(m, n, h);
    m = res(m, x, n, h);
    output(m, n, h);
}