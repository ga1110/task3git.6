﻿#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    double n, y, y1, y2, a;
    cout << "n= ";
    cin >> n;
    cout << "y1 = " << 0.5 << "\n"; // 1 элемент последовательности (по условию)
    cout << "y2 = " << 0.4 << "\n"; // 2 элемент последовательности (по условию)
    y1 = 0.5;
    y2 = 0.4;
    for (a = 3; a <= n; a += 1) { // цикл для вывода до n-ого элемент последовательности 
        y = (1 / 2.0) * y2 + (1 / 3.0) * y1; // формула вычисления следующего элемента последовательности 
        cout << "y" << a << " = " << y << "\n"; // выводим нужный элемент
        y1 = y2; // меняем первый на второй 
        y2 = y; // меняем второй на текущий 
    }


}
