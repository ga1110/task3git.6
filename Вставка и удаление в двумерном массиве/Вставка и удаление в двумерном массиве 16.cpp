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
int max(int** m, int n, int h) {// функия поиска максимального элемента 
    int x = m[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            if (x < m[i][j]) {
                x = m[i][j];
            }
        }
    }
    cout << "Max = " << x;
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
int check(int** m, int j, int n, int x) {// функция проверки столбца
    for (int i = 0; i < n; i++) {
        if (m[i][j] == x) {
            return 1;
        }
    }
    return 0;
}
int** res(int** m, int x, int n, int& h) {// функция решения 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            if (check(m, j, n, x) == 1) { // если содержит максимальный элемент
                for (int y = 0; y < n; y++) {// сдвигаем столбец вправо 
                    for (int u = j; u < h; u++) {
                        m[y][u] = m[y][u + 1];
                    }
                }
                h--;
            }

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
    int x = max(m, n, h);
    output(m, n, h);
    m = res(m, x, n, h);
    output(m, n, h);
}