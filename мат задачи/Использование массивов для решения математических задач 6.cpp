#include <iostream>
using namespace std;
int* input(int n) { //cоздание массива
    //ввод массива
    int* m = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        cout << "m[" << i << "] = ";
        cin >> m[i];
    }
    //
    return m;
}
int* output(int* m, int n) {
    for (int i = 0; i < n + 1; i++) {
        if (m[i] == 0) {
            i++;
        }
        else {
            cout << m[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}
int* res(int* m, int* a, int n, int A, int d) { // умножаем коэф. на степень x
    for (int i = 0; i < n + 1 + d; i++) {
        if (i < n + 1) {
            if (i < d) {
                a[i] = m[i];
            }
            else {
                a[i] = m[i] - (m[i - d] * A);
            }
        }
        else { // элементы многочлена закончились и мы добавляем новые 
            if (d >= n) {
                a[i] = m[i - (n + 1)] * (-A);
            }
            else {
                a[i] = m[i - d] * (-A);
            }
        }
    }
    return a;
}
int* output_res(int* m, int n, int d) {
    if (d > n) {
        for (int i = 0; i < 2 * n + 2; i++) {
            if (m[i] == 0) { // пропускаем нули 
                i++;
            }
            else {
                cout << m[i] << ' ' << i << "\n";
            }

        }
    }
    else {
        for (int i = 0; i < n + 1 + d; i++) {
            if (m[i] == 0) { // пропускаем нули 
                i++;
            }
            else {
                cout << m[i] << ' ';
            }

        }
    }

    cout << "\n";
    return 0;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n, d, A, c;
    cout << "Степень x = ";
    cin >> d; //d - степень x
    cout << "A = ";
    cin >> A;
    cout << "n = ";
    cin >> n;
    int* m = input(n);
    output(m, n);
    int* a = new int[n + 1 + d];
    res(m, a, n, A, d);
    output_res(a, n, d);
}