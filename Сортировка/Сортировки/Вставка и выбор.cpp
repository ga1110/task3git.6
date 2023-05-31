#include <iostream>
using namespace std;

//генерируем целый случайный массив
int* new_mass(int n){
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = 1 + rand() % 10;
    }
    return a;
}
void out_mass(int* a, int n) {

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void out_mass_w_i(int* a, int n,int i) {

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "i = " << i;
    cout << endl;
}
void out_mass_w_i_n_j(int* a, int n, int i, int j) {

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "i = " << i <<" "<<"j = "<<j;
    cout << endl;
}
void heapify(int* a, int i, int n) {
    int max = i;
    while (true) {
        int child = 2 * i + 1; //л
        if (child < n && a[child] > a[max]) {
            max = child;
        }
        child++;
        if (child < n && a[child] > a[max]) {
            max = child;
        }
        if (max == i) {
            break;
        }
        else {
            swap(a[max], a[i]);
            i = max;
        }
    }

}
int* sorting_by_choice(int *a, int n) {
    for (int i = 0; i < n; i++) {
        out_mass_w_i(a, n, i);
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (i != min) {
            swap(a[i], a[min]);
        }
    }
    return a;
}
int* sorting_by_insert(int* a, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--) {
            a[j + 1] = a[j];
            out_mass_w_i_n_j(a, n, i, j);
        }
        a[j + 1] = temp;
    }
    return a;
}
int main()
{
    setlocale(LC_ALL, "rus");
    int* a;
    int n = 9;
    int *b = new int[n];
    a = new_mass(n);
    for (int i = n / 2; i >= 0; i--) {
        heapify(a, i, n);
    }
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    cout << "Исходная куча: ";
    out_mass(a, n);
    cout << "\n";
    cout << "Сортировка выбором:" << endl;
    a = sorting_by_choice(a, n);
    cout << "\n";
    cout << "Исходная куча: ";
    out_mass(b, n);
    cout << "\n";
    cout << "Сортировка вставками:" << endl;
    b = sorting_by_insert(b, n);
    system("pause");
    
}