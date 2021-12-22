#include <bits/stdc++.h>

#define MAX 10

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a[MAX];
    for (int i = 0; i < MAX; ++i){
        a[i] = 0xFFFFFFFF;
        cout << a[i] << " " << flush;
    }
    cout << endl;

    memset(a, 0, MAX*sizeof(int));
    for (int i = 0; i < MAX; ++i){
        cout << a[i] << " " << flush;
    }
    cout << endl;

    return 0;
}
