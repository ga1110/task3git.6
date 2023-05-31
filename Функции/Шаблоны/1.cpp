#include<iostream>
using namespace std;

template <typename X>
X** create(X c, int n, int h) {//Ввод массива
    X** m = new X * [2 * n + 1];
    for (int i = 0; i < 2 * n + 1; i++) {
        m[i] = new X[2 * n + 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < h; j++) {
            cin >> m[i][j];
        }
    }
    cout << "\n";
    return m;
}
template <typename X>
void out(X** m, int n, int h) {//Вывод 
    for (int i = 0; i < n; i++, cout << endl) {
        for (int j = 0; j < h; j++) {
            cout << m[i][j] << " ";
        }

    }
    cout << "\n";
}
template <typename X>
X** res(X** m, int n, int h) {//Решение
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < h; j++) {
            swap(m[i][j], m[n - i - 1][j]);
        }
    }
    return m;
}
int main() {
    setlocale(LC_ALL, "rus");
    int n, h, k;
    cout << "n = "; cin >> n;
    cout << "h = "; cin >> h;
    char c;
    do {
        cout << "Введите тип:\n1 - int\n2 - double\n3 - char\n4 - float\n";
        cin >> k; cout << "\n";
        switch (k) {
        case 1:
        {
            int c = 1;
            int** m = create(c, n, h);
            out(m, n, h);
            m = res(m, n, h);
            out(m, n, h);
            break;
        }
        case 2:
        {
            double c1 = 1;
            double** m = create(c1, n, h);
            out(m, n, h);
            m = res(m, n, h);
            out(m, n, h);
            break;
        }
        case 3:
        {
            char c2 = '1';
            char** m = create(c2, n, h);
            out(m, n, h);
            m = res(m, n, h);
            out(m, n, h);
            break;
        }
        case 4:
        {
            float c3 = 1;
            float** m = create(c3, n, h);
            out(m, n, h);
            m = res(m, n, h);
            out(m, n, h);
            break;
        }
        default: cout << "Неправильно введены данные\n";
        }
        cout << "Еще раз? Y - да, N - нет\n";
        cin >> c;
    } while (c != 'N');
    return 0;
}
