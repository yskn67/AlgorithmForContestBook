#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10000
#define INF 100001

int n;
vector<pair<int, int> > G[MAX];
int d[MAX];
int done[MAX];

void setShortestPath() {
    int i, u, c, v;
    priority_queue<pair<int, int> > pq;
    d[0] = 0;
    pq.push(make_pair(0, 0));
    
    while(!pq.empty()) {
        pair<int, int> f = pq.top();
        pq.pop();
        u = f.second;
        c = f.first;
        done[u] = 1;

        if(d[u] < c * (-1)) continue;

        for(i = 0; i < G[u].size(); i++) {
            v = G[u][i].first;
            c = G[u][i].second;
            if(done[v] != 1 && d[v] > d[u] + c) {
                d[v] = d[u] + c;
                pq.push(make_pair(d[v] * (-1), v));
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
        for(j = 0; j < k; j++) {
            cin >> e >> c;
            G[i].push_back(make_pair(e, c));
        }
    }
    setShortestPath();
    for(i = 0; i < n; i++) {
        cout << i << " " << d[i] << endl;
    }
    return 0;
}
