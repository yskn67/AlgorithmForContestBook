#include <iostream>
#include <vector>
using namespace std;
#define MAX 100000
#define QMAX 10000
#define NIL -1

int n;
vector<int> G[MAX];
int group[MAX];

void dfs(int r, int g) {
    group[r] = g;
    for(int i = 0; i < G[r].size(); i++) {
        if(group[G[r][i]] == NIL) dfs(G[r][i], g);
    }
    return;
}

void assignGroup() {
    int i;
    int id = 1;
    for(i = 0; i < n; i++) group[i] = NIL;
    for(i = 0; i < n; i++) {
        if(group[i] == NIL) dfs(i, id++);
    }
    return;
}

int main() {
    int m, q, s, t, i;
    cin >> n >> m;
    for(i = 0; i < m; i++) {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    assignGroup();
    cin >> q;
    for(i = 0; i < q; i++) {
        cin >> s >> t;
        if(group[s] == group[t]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
