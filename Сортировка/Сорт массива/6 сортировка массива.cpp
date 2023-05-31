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
void Shell_sort_u(vector<people>& x, int size) { //Функция сортировки
    int n = size;
    int s = 0;
    int step = n / (pow(2, s));
    while (step > 1) {
        int step = n / (pow(2, s));
        for (int i = 0; i < n - step; i++) {
            int j = i;
            while ((j >= 0) && (x[j + step] > x[j])) {
                swap(x[j], x[j + step]);
                j -= step;
            }
        }
        s++;
        if (step == 0) {
            break;
        }
    }
}
void Shell_sort_v(vector<people>& x, int size) { //Функция сортировки
    int n = size;
    int s = 0;
    int step = n / (pow(2, s));
    while (step > 1) {
        int step = n / (pow(2, s));
        for (int i = 0; i < n - step; i++) {
            int j = i;
            while ((j >= 0) && (x[j + step] < x[j])) {
                swap(x[j], x[j + step]);
                j -= step;
            }
        }
        s++;
        if (step == 0) {
            break;
        }
    }
}

void sorting(int**& mas) {
    vector<int> x;
    int i, j;
    for (i = 0; i < size_n; i++) {
        for (j = 0; j < size_n; j++) {
            x.push_back(mas[j][i]);
        }
        if (i % 2 == 0) {
            Shell_sort_u(x, size_n);
        }
        else {
            Shell_sort_v(x, size_n);
        }

        for (int h = 0; h < size_n; h++) {
            mas[h][i] = x[h];
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





