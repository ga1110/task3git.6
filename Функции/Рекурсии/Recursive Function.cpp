#include <iostream>
using namespace std;
int H(int x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 2 * x;
    }
    return 2 * x * H(n - 1, x) - 2 * n * H(n - 2, x);
}
int main()
{
    int x, n, f;
    cout << "x = "; cin >> x;
    cout << "n = "; cin >> n;
    f = H(x, n);
    cout << f;
}
