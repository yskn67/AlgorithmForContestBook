#include <iostream>
#include <queue>
using namespace std;
#define MAX 100
#define NIL -1

int n;
int G[MAX+1][MAX+1];
int D[MAX+1];
queue<pair<int, int> > Q;

void search() {
    pair<int, int> now = Q.front();
    Q.pop();

    for(int i = 1; i <= n; i++) {
        if(G[now.first][i] == 1 && D[i] == NIL) {
            D[i] = now.second + 1;
            pair<int, int> n = make_pair(i, now.second + 1);
            Q.push(n);
        }
    }
    return;
}


int main() {
    int u, k, v, i, j;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> u >> k;
        D[i+1] = NIL;
        for(j = 1; j <= n; j++) G[u][j] = 0;
        for(j = 0; j < k; j++) {
            cin >> v;
            G[u][v] = 1;
        }
    }
    pair<int, int> start = make_pair(1, 0);
    D[1] = 0;
    Q.push(start);
    while(!Q.empty()) search();
    for(i = 1; i <= n; i++) {
        cout << i << " " << D[i] << endl;
    }
    return 0;
}
