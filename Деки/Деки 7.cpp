#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>
using namespace std;
int a, b, X;
bool kratn_2(int x) {
    if (x % 2 == 0) {
        return true;
    }
    return false;
}
bool kratn_x(int x) {
    if (x % X == 0) {
        return true;
    }
    return false;
}
bool if_max(int x) {
    if (x == max_v) {
        return true;
    }
    return false;
}
void print(list<int>l) {
    for (list<int>::iterator it = l.begin(); it != l.end(); l++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    int n1, n, x, t;
    setlocale(LC_ALL, "russian");
    list<int> l1;
    list<int> l2;
    cout << "Размерность 1 послд: "; cin >> n;
    cout << "Размерность 2 послд: "; cin >> n1;
    for (int i = 0; i < n; i++) {
        cin >> t;
        l1.push_back(t);
    }
    for (int i = 0; i < n1; i++) {
        cin >> t;
        l2.push_back(t);
    }
    print(l1);
    print(l2)
    system("pause");
}