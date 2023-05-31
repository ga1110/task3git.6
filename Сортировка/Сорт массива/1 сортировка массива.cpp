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
            output << m[i][j] <<" ";
        }
        output << "\n";
    }
}
void Quick_sort(vector<people>& x, int start, int end) { //Функция сортировки
    int i = start; //Начальный элемент
    int j = end; //Конечный элемент
    int m = x[(i + j) / 2].pay; //Средний элемент (Опорный элемент) 
    while (i <= j) {
        while (x[i].pay < m) { //Пока элемент под номером i меньше опорного 
            i++;
        }
        while (m < x[j].pay) { //Пока элемент под номером j больше опорного
            j--;
        }
        if (i <= j) { //Если i <= j
            swap(x[i], x[j]); //меняем местами
            i++;
            j--;
        }

    }
    if (start < j) { //Рекурсивные запуски сортировки
        Quick_sort(x, start, j);
    }
    if (i < end) {
        Quick_sort(x, i, end);
    }
}
void sorting(int**& mas) {
    vector<int> x;
    for (int i = 0; i < size_n; i++) {
        for (int j = 0; j < size_n; j++) {
            x.push_back(mas[j][i]);
        }
        Quick_sort(x, 0, size_n - 1);
        for (int h = 0; h < size_n; h++) {
            mas[h][i] = x[h];
        }
        x.clear();
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    int **x;
    x = inFile();
    sorting(x);
    OutFile(x);
}





