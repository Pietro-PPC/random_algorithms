#include <bits/stdc++.h>

#define MAX 1000
using namespace std;

struct w_graph {
    list< pair<int,int> > l[MAX];
    int w;
    int size; 
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    struct w_graph G;
    cin >> G.size;
    int v1, v2, w, n;

    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> v1 >> v2 >> w;
        G.l[v1].push_back( make_pair(v2, w) );
        G.l[v2].push_back( make_pair(v1, w) );
    }

    return 0;
}
