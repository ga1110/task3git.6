#include <iostream>
#include <cmath>
using namespace std;
long double f(long double n, long double i) {
    if ((n - i) <= 0) {
        return sqrt(1 + n);
    }
    return sqrt(1 + i * (f(n, i + 1)));

}
int main()
{
    long double n, s;
    cout << "n = "; cin >> n;
    s = f(n, 2);
    cout << s;
}