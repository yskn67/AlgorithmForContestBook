#include <iostream>
using namespace std;

int main() {
    int n, u, k, v, i, j;
    cin >> n;
    int G[n+1][n+1];
    for(i = 0; i < n; i++) {
        cin >> u >> k;
        for(j = 1; j <= n; j++) G[u][j] = 0;
        for(j = 0; j < k; j++) {
            cin >> v;
            G[u][v] = 1;
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(j-1) cout << " ";
            cout << G[i][j];
        }
        cout << endl;
    }
    return 0;
}
