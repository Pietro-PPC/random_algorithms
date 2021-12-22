/* 
  Algoritmo de busca que retorna a componente 
  de cada vértice no grafo de entrada
*/

#include <bits/stdc++.h>

#define MAX 100

using namespace std;


void iterateComponent(bool (&G)[MAX][MAX], int n, int r, int (&component)[MAX], int (&state)[MAX]){
    vector<int> v1;
    v1.push_back(r);
    state[r] = 1;
    while (!v1.empty()){
        int v = *(v1.end() - 1);
        v1.pop_back();
        for (int i = 0; i < n; ++i){
            if (G[v][i] && !state[i]){
                component[i] = component[r];
                v1.push_back(i);
                state[i] = 1;
            }
        }
        state[v] = 2;
    }
}

void getComponents(bool (&G)[MAX][MAX], int n, int (&component)[MAX]){
    int state[MAX];
    int c = 0;
    for (int i = 0; i < n; ++i){
        state[i] = 0;
        component[i] = 0;
    }
    for (int i = 0; i < n; ++i){
        if(state[i] == 0){
            component[i] = ++c;
            iterateComponent(G, n, i, component, state);
        }
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

    int component[MAX];
    getComponents(G, n, component);
    for (int i = 0; i < n; ++i){
        cout << "Vertice " << i << ": " << component[i] << endl;
    }

    return 0;
}
