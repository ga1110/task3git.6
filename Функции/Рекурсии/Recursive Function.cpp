#include <iostream>
using namespace std;
long double factorial(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    else {
        return n*factorial(n - 1);
    }
}
int main()
{
    int n, f;
    cout << "n = "; cin >> n;
    f = 1;
    f = factorial(n);
    cout<<"\n" << f;
}

