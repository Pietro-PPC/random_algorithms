/*
  Algoritmo de busca em largura que retorna a distância de cada
  vértice do grafo em relação ao vértice 0 da matriz de entrada
*/

#include <bits/stdc++.h>

#define MAX 100

using namespace std;

void getDistances(bool (&G)[MAX][MAX], int n, int r, int (&distance)[MAX]){
    int state[MAX];
    for (int i = 0; i < n; ++i)
        state[i] = 0;

    queue<int> v1;
    v1.push(r);
    state[r] = 1;
    
    distance[r] = 0;
    while(!v1.empty()){
        int v = v1.front();
        v1.pop();
        for (int i = 0; i < n; ++i){
            if (i != v && G[v][i] && !state[i]){
                v1.push(i);
                state[i] = 1;
                distance[i] = distance[v]+1;
            }
        }
        state[v] = 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool G[MAX][MAX];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        for (int j = 0 ;j < n; ++j){
            cin >> G[i][j];
        }
    }

    int distances[MAX];
    getDistances(G, n, 0, distances);
    for (int i = 0; i < n; ++i){
        cout << "Vertice " << i << ": " << distances[i] << endl;
    }

    return 0;
}
