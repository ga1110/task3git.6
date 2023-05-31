#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>
using namespace std;
int a, b, X, Y;
bool diap(int x) {//прроверка нахождения числа в диапозоне
    if (x <=b && x >= a) {
        return true;
    }
    return false;
}
bool kratn_x(int x) {//проверка кратности на х
    if (x % X == 0) {
        return true;
    }
    return false;
}
void print(list<int>l) { //функция вывода
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
list<int> operator +(list<int> l1, list<int> l2) { //переопределение оператора +
    l1.sort(); //сортировка 
    l2.sort(); //сортировка 
    l1.merge(l2); //объединение
    l1.sort(); //сортировка 
    return l1;
}
int main()
{
    int n1, n, x, t;
    setlocale(LC_ALL, "russian");
    list<int> l1;//создаем лист
    list<int> l2;//создаем лист
    list<int> ans;//создаем лист
    cout << "X = "; cin >> X;
    cout << "Y = "; cin >> Y;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "Размерность 1 послд: "; cin >> n;
    cout << "Размерность 2 послд: "; cin >> n1;
    for (int i = 0; i < n; i++) { //заполняем лист
        cin >> t;
        l1.push_back(t);
    }
    for (int i = 0; i < n1; i++) { //заполняем лист
        cin >> t;
        l2.push_back(t);
    }
    print(l1); //вывод на экран
    print(l2); //вывод на экран
    list<int>::iterator it = remove_if(l1.begin(), l1 .end(), kratn_x); //переносим элементы кратные x в конец списка
    l1.erase(it, l1.end()); //удаляем элементы
    replace_if(l2.begin(), l2.end(), diap, Y); //заменяем числа из диапозона на У
    ans = l1 + l2; //получаем ответ
    print(ans); //выводим ответ на экран
    system("pause");
}