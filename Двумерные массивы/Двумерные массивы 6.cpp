#include <iostream>
using namespace std;
int** in_mas(int n) {
    int** m = new int* [n+1];
    for (int i = 0; i < n + 1; i++) {
        cout << "m[" << i << "] = ";
        cin >> m[i];
    }
    return m
}
int main()
{
    setlocale(LC_ALL, "rus");
    int** m = create(n);
    for (int i = 0; i < n + 1; i++) {
        cout << m[i] << "\n";
    }
}