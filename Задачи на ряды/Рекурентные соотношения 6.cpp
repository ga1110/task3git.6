#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    long double x, y, z, n, i, a, b, c;
    cout << "z = ";
    cin >> z;
    cout << "x = ";
    cin >> b;
    y = 1; // x в степени n
    n = 1; // факториал 
    a = 1; // сумма последовательности 
    for (x = 1; x <= z; x += 1) {
        n = 1;
        for (i = 1; i < x + 1; i++) { // цикл для факториала 
            n *= i;
        }
        y = (pow(b, x)) / (n);
        a += y;
    }
    cout << a;
}
