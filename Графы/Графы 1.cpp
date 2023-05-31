#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

// Функция для подсчета количества смежных вершин
int countAdjacentVertices(vector<vector<int>>& adjacencyList, int vertex) {
    // Получаем список смежных вершин для данной вершины
    vector<int>& adjacentVertices = adjacencyList[vertex];

    // Возвращаем количество смежных вершин
    return adjacentVertices.size();
}

int main() {
    int n, m, x, y;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    vector<vector<int>> Gr;
    Gr.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x > n || y > n) {
            continue;
        }
        else {
            Gr[x].push_back(y);
            Gr[y].push_back(x);
        }
    }
    for (int i = 0; i < n; i++) {
        sort(Gr[i].begin(), Gr[i].end());
        Gr[i].erase(unique(Gr[i].begin(), Gr[i].end()), Gr[i].end());
    }
}