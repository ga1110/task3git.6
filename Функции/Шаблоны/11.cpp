#include<iostream>
using namespace std;
template <typename X>
X* create_x(X c, int n) {
    X* m = new X[n];
    cout << "X = ";
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    cout << "\n";
    return m;
}
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
X** res(X** m, X* x, int n, int h) {
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < h; j++) {
            swap(m[i][j], x[j]);
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
            int* x = create_x(c, n);
            int** m = create(c, n, h);
            out(m, n, h);
            m = res(m, x, n, h);
            out(m, n, h);
            break;
        }
        case 2:
        {
            double c1 = 1;
            double* x = create_x(c1, n);
            double** m = create(c1, n, h);
            out(m, n, h);
            m = res(m, x, n, h);
            out(m, n, h);
            break;
        }
        case 3:
        {
            char c2 = '1';
            char* x = create_x(c2, n);
            char** m = create(c2, n, h);
            out(m, n, h);
            m = res(m, x, n, h);
            out(m, n, h);
            break;
        }
        case 4:
        {
            float c3 = 1;
            float* x = create_x(c3, n);
            float** m = create(c3, n, h);
            out(m, n, h);
            m = res(m, x, n, h);
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
