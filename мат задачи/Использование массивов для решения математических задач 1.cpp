#include <iostream>
using namespace std;
// Ищем производную от многочлена 
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
int* res(int* m, int n) { // умножаем коэф. на степень x
    for (int i = n; i > -1; i -= 1) {
        m[n - i] = m[n - i] * i;
    }
    return m;
}
int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    setlocale(LC_ALL, "rus");
    int* m = input(n);
    output(m, n);
    res(m, n);
    output(m, n);
}