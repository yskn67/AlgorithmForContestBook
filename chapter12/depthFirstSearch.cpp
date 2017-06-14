#include <iostream>
using namespace std;
#define MAX 100
#define NIL -1

int n;
int G[MAX+1][MAX+1];
pair<int, int> times[MAX+1];


int search(int now, int time) {
    times[now].first = time;
    time++;
    for(int i = 1; i <= n; i++) {
        if(G[now][i] == 1 && times[i].first == NIL) {
            time = search(i, time);
        }
    }
    times[now].second = time;
    time++;
    return time;
}


int main() {
    int u, k, v, i, j;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> u >> k;
        times[i+1].first = times[i+1].second = NIL;
        for(j = 1; j <= n; j++) G[u][j] = 0;
        for(j = 0; j < k; j++) {
            cin >> v;
            G[u][v] = 1;
        }
    }
    search(1, 1);
    for(i = 1; i <= n; i++) {
        cout << i << " " << times[i].first << " " << times[i].second << endl;
    }
    return 0;
}
