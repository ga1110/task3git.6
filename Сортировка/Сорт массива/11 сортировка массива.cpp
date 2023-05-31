#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
ifstream input("F:\\Учеба\\Задачи c++\\Сортировка\\Сорт массиа\\Сортировка_ввод.txt"); //файл из которого берем данные 
ofstream output("F:\\Учеба\\Задачи c++\\Сортировка\\Сорт массиа\\Сортировка_вывод.txt"); //файл в который будем записыать даннные
int size_n;
int** inFile() { //заполняем вектор информацией о людях 
    input >> size_n;
    int** mass = new int* [size_n];
    for (int i = 0; i < size_n; i++)
        mass[i] = new int[size_n];
    for (int i = 0; i < size_n; i++) {
        for (int j = 0; j < size_n; j++) {
            input >> mass[i][j];
        }
    }
    return mass;
}

void OutFile(int** m) { //Функция записи данных в файл
    for (int i = 0; i < size_n; i++) {
        for (int j = 0; j < size_n; j++) {
            output << m[i][j] << " ";
        }
        output << "\n";
    }
}
void Bubble_sort(vector<int>& x, int size) { //Функция сортировки
    for (int i = 0; i < size - 1; i++) {
        for (int j = size - 1; j > 0; j--) {
            if (x[j] < x[j - 1]) {
                swap(x[j - 1], x[j]);
            }
        }
    }
}
void sorting(int**& mas) {
    vector<int> x;
    int i, j, k;
    for (k = 1; k < 2 * size_n - 2; k++) {
        for (i = 0; i < size_n; i++) {
            if (((k - i) < size_n) && (k - i >= 0)) {
                x.push_back(mas[i][k - i]);
            }
        }
        Bubble_sort(x, x.size());
        int L = 0;
        for (i = 0; i < size_n; i++) {
            if (((k - i) < size_n) && (k - i >= 0)) {
                mas[i][k - i] = x[L];
                L++;
            }
        }
        x.clear();
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    int** x;
    x = inFile();
    sorting(x);
    OutFile(x);
}





