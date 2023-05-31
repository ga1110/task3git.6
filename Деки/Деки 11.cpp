#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include<deque>
#include<list>
bool kratn(int x) {
    if (x % 2 == 0) {
        return true;
    }
    return false;
}
bool ne_kratn(int x) {
    if (x % 2 == 0) {
        return false;
    }
    return true;
}
using namespace std;
int main()
{
    int n, n1, t;
    setlocale(LC_ALL, "russian");
    list<int> x;
    list<int> y;
    cout << "Размерность 1 послд: "; cin >> n;
    cout << "Размерность 2 послд: "; cin >> n1;
    for (int i = 0; i < n; i ++) {
        cin >> t;
        x.push_back(t);
    }
    for (int i = 0; i < n1; i++) {
        cin >> t;
        y.push_back(t);
    }
    for (list<int>::iterator it = x.begin(); it != x.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for (list<int>::iterator it = y.begin(); it != y.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    list<int>::iterator it = remove_if(x.begin(), x.end(), kratn);
    x.erase(it, x.end());
    for (list<int>::iterator it = x.begin(); it != x.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    list<int>::iterator it1 = remove_if(y.begin(), y.end(), ne_kratn);
    y.erase(it1, y.end());
    for (list<int>::iterator it1 = y.begin(); it1 != y.end(); it1++) {
        cout << *it1 << " ";
    }
    cout << endl;
    x.sort();
    y.sort();
    x.merge(y);
    for (list<int>::iterator it2 = x.begin(); it2 != x.end(); it2++) {
        cout << *it2 << " ";
    }
    cout << endl;
}