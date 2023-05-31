#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include<deque>
int X;
bool kratn(int x) {
    if (x % X == 0) {
        return false;
    }
    return true;
}
bool kratn_2(int x) {
    if (x % 2 == 0) {
        return true;
    }
    return false;
}
using namespace std;
int main()
{
    int n, x;
    setlocale(LC_ALL, "russian");
    deque<int> d;
    cout << "X = "; cin >> X;
    cout << "Размерность вектора: "; cin >> n;
    for (int i = 0; i < n; i++) {//ÑÐ¾Ð·Ð´Ð°Ð½Ð¸Ðµ Ð²ÐµÐºÑ‚Ð¾Ñ€Ð°
        cout << "vec[" << i << "] = ";
        cin >> x;
        d.push_back(x);
    }
    deque<int>d1(d);
    for (deque<int>::iterator iter = d.begin(); iter != d.end(); iter++) {//Ð²Ñ‹Ð²Ð¾Ð´
        cout << *iter << " ";
    }
    cout << endl;
    replace_if(d1.begin(), d1.end(), kratn, 0);
    cout << "Сумма кратных X: "<< accumulate(d1.begin(), d1.end(), 0) << endl;
    cout << endl;
    int max = *max_element(d.begin(), d.end());
    cout << "Мин: " << *min_element(d.begin(), d.end()) << endl;
    deque<int>d2(d);
    replace_if(d2.begin(), d2.end(), max, kratn_2);
    for (deque<int>::iterator iter = d2.begin(); iter != d2.end(); iter++) {//Ð²Ñ‹Ð²Ð¾Ð´
        cout << *iter << " ";
    }
}