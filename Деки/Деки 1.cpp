#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
pair<int, int>a;
bool odd(int x) {
    if (x < a.first || x > a.second) {
        return false;
    }
    return true;
}
pair<int, int> create_r() {
    int x, y;
    cout << "Первое число интервала:"; cin >> x;
    cout << "Второе число интервала:"; cin >> y;
    if (x < y) {
        a.first = x;
        a.second = y;
    }
    else {
        a.first = x;
        a.second = y;
    }
    return a;
}
int main()
{
    int n, x, summ;
    setlocale(LC_ALL, "russian");
    a = create_r();
    vector<int> v;
    cout << "Размерность вектора: "; cin >> n;
    for (int i = 0; i < n; i++) {//ÑÐ¾Ð·Ð´Ð°Ð½Ð¸Ðµ Ð²ÐµÐºÑ‚Ð¾Ñ€Ð°
        cout << "vec[" << i << "] = ";
        cin >> x;
        v.push_back(x);
    }
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {//Ð²Ñ‹Ð²Ð¾Ð´
        cout << *iter << " ";
    }
    cout << endl;
    vector<int>::iterator it = remove_if(v.begin(), v.end(), odd);
    v.erase(it, v.end());
    cout << endl;
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {//Ð²Ñ‹Ð²Ð¾Ð´
        cout << *iter << " ";
    }
    cout << endl;
    cout << "Сумма = " << accumulate(v.begin(), v.end(), 0) << endl;
}