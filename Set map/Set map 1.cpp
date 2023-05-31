#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <string_view>
using namespace std;
int main()
{
    int n, t;
    set<int>a, b, c;
    cout << "n = "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = "; cin >> t;
        a.insert(t);
    }
    for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
        if (*it >= 10 && *it <= 100) {
            t = *it;
            while (t > 0) {
                b.insert(t % 10);
                t /= 10;
            }
        }
        else {
            t = *it;
            while (t > 0) {
                c.insert(t % 10);
                t /= 10;
            }
        }
    }
    a.clear();
    cout << endl;
    for (set<int>::iterator it = b.begin(); it != b.end(); it++) {
        a.insert(*find_if(it, b.end(), [&](int a) {
            return c.count(a) == 0; }));
    }
    for (set<int>::iterator it = a.begin(); it != a.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    system("pause");
}



