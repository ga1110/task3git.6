#include<iostream>
#include<string>
#include <fstream>
#include <cmath>
using namespace std;
struct points {
    string point;
    int x, y;
    long double dist;
};

int main()
{
    setlocale(LC_ALL, "rus");
    int n, i, j, mem;
    float max;
    n = 3;
    points* arr = new points[n];
    for (i = 0; i < n; i++) {
        cout << "Координаты " << i + 1 << " точки: \n";
        cout << "x = "; cin >> arr[i].x;
        cout << "y = "; cin >> arr[i].y;
        arr[i].point = "(" + to_string(arr[i].x) + ";" + to_string(arr[i].y) + ")";
        arr[i].dist = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j != i) {
                arr[i].dist += sqrt((arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y));
            }
        }
    }
    mem = 0;
    max = arr[0].dist;
    for (i = 0; i < n; i++) {
        if (max < arr[i].dist) {
            max = arr[i].dist;
            mem = i;
        }
    }
    cout << "Точка номер " << mem + 1 << endl;
    cout << "Координаты " << arr[mem].point << endl;
    cout <<"Сумма растояний " << arr[mem].dist << endl;
    system("pause");
}
