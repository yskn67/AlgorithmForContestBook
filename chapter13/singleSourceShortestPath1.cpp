#include <iostream>
using namespace std;
#define MAX 100
#define INF 100001

int n;
int G[MAX][MAX];
int d[MAX];
int done[MAX];

void setShortestPath() {
    int i, min, u;
    d[0] = 0;
    
    while(1) {
        min = INF;
        for(i = 0; i < n; i++) {
            if(done[i] != 1 && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        if(min == INF) break;
        done[u] = 1;

        for(i = 0; i < n; i++) {
            if(done[i] != 1 && G[u][i] < INF) {
                if(d[u] + G[u][i] < d[i]) {
                    d[i] = d[u] + G[u][i];
                }
            }
        }
    }
    return;
}

int main() {
    int i, j, k, u, e, c;
    cin >> n;
    for(i = 0; i < n; i++) {
        d[i] = INF;
        done[i] = 0;
        cin >> u >> k;
        for(j = 0; j < n; j++) G[i][j] = INF;
        for(j = 0; j < k; j++) {
            cin >> e >> c;
            G[i][e] = c;
        }
    }
    setShortestPath();
    for(i = 0; i < n; i++) {
        cout << i << " " << d[i] << endl;
    }
    return 0;
}
