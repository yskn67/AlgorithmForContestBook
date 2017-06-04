#include <iostream>
using namespace std;
#define MAX 25
#define NIL -1

struct Node { int p, l, r; };

Node T[MAX];
int n, D[MAX], H[MAX];


void setDepth(int u, int d) {
    D[u] = d;
    if(T[u].r != NIL) setDepth(T[u].r, d + 1);
    if(T[u].l != NIL) setDepth(T[u].l, d + 1);
}

int setHeight(int u) {
    int h1 = 0, h2 = 0;
    if(T[u].r != NIL) {
        h1 = setHeight(T[u].r) + 1;
    }
    if(T[u].l != NIL) {
        h2 = setHeight(T[u].l) + 1;
    }
    H[u] = max(h1, h2);
    return H[u];
}

int getSibling(int u) {
    if(T[u].p == NIL) return NIL;
    else if(T[T[u].p].l == u) return T[T[u].p].r;
    else  return T[T[u].p].l;
}

int getDegree(int u) {
    int d = 0;
    if(T[u].r != NIL) d++;
    if(T[u].l != NIL) d++;
    return d;
}

void print(int u) {
    int i, c;
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].p << ", ";
    cout << "sibling = " << getSibling(u) << ", ";
    cout << "degree = " << getDegree(u) << ", ";
    cout << "depth = " << D[u] << ", ";
    cout << "height = " << H[u] << ", ";

    if(T[u].p == NIL) cout << "root";
    else if(T[u].l == NIL) cout << "leah";
    else cout << "internal node";

    cout << endl;
}

int main() {
    int i, u, l, r;
    cin >> n;
    for(i = 0; i < n; i++) T[i].p = T[i].l = T[i].r = NIL;

    for(i = 0; i < n; i++) {
        cin >> u >> l >> r;
        T[u].l = l;
        T[u].r = r;
        if(l != NIL) T[l].p = u;
        if(r != NIL) T[r].p = u;
    }

    for(i = 0; i < n; i++) setHeight(i);
    setDepth(0, 0);

    for(i = 0; i < n; i++) print(i);
    return 0;
}
