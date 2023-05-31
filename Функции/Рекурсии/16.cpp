#include <iostream>
#include <cmath>
using namespace std;
int out(int n) {
    for (int i = 0; i < n; i++) {
        cout << n;
    }
    cout << "\n";
    return 1;
}
int f(int n, int i, int k) {
    if (i < n && k == 0) {
        out(i);
        return f(n, i + 2, k);
    }
    if (i == n) {
        k++;
        out(n);
    }
    if (i > 0 && k == 1) {
        out(i);
        return f(n, i - 2, k);
    }
}
int main()
{
    int n;
    cin >> n;
    f(n, 1, 0);
}