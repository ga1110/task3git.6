#include <iostream>
using namespace std;
int** create(int n, int h) {// функция создания и ввода двумерного массива 
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
int min(int** m, int n, int h) {// функия поиска минимального элемента 
    int x = m[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            if (x > m[i][j]) {
                x = m[i][j];
            }
        }
    }
    cout << "Min = " << x;
    cout << "\n";
    return x;
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
int check(int** m, int i, int h, int x) {// функция проверки строки
    for (int j = 0; j < h; j++) {
        if (m[i][j] == x) {
            return 1;
        }
    }
    return 0;
}
int** res(int** m, int x, int& n, int h) {// функция решения 
    for (int i = 0; i < n; i++) {
        if (check(m, i, h, x) == 1) { // если строка содержит минимальный элемент
            for (int j = i; j < n; j++) {
                for (int t = 0; t < h; t++) {// сдвигаем строку i вниз
                    m[j][t] = m[j + 1][t];
                }

            }
            n--;
            i--;
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
    int** m = create(n, h);
    int x = min(m, n, h);
    output(m, n, h);
    m = res(m, x, n, h);
    output(m, n, h);
}