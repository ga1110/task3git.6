#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    long double x, i, n, a, b, c;
    cout << "n = ";
    cin >> n;
    cout << "x = ";
    cin >> x;
    a = x; // первый элемент 
    b = -1;// -1
    c = 1; // переменная для стпени -1
    for (i = 3; i < n + 1; i += 2) { // цикл для последовательности 
        a += pow(b, c) * ((pow(x, i)) / i);
        c++;
    }
    cout << a;
}
    