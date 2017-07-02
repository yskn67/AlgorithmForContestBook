#include <iostream>
#define MAX 10000
using namespace std;

int n;
struct Node {
    int parent;
    int rank;
};
Node *tree[MAX];

void makeSet(int x) {
    if(tree[x] != NULL) return;
    tree[x] = (struct Node*) malloc(sizeof(struct Node));
    tree[x]->parent = x;
    tree[x]->rank = 0;
    return;
}

int findSet(int x) {
    if(tree[x] == NULL) return -1;
    if(x == tree[x]->parent) {
        tree[x]->rank = 0;
        return x;
    }
    int rep = findSet(tree[x]->parent);
    if(rep != -1) {
        tree[x]->parent = rep;
        if (tree[rep]->rank < tree[x]->rank + 1) {
            tree[rep]->rank = tree[x]->rank + 1;
        }
    }
    return rep;
}

void unite(int x, int y) {
    if(tree[x] == NULL) makeSet(x);
    if(tree[y] == NULL) makeSet(y);

    int xRep = findSet(x);
    int yRep = findSet(y);

    if(xRep == yRep) return;

    if(tree[xRep]->rank == tree[yRep]->rank) {
        tree[xRep]->parent = yRep;
        tree[yRep]->rank++;
    } else if(tree[xRep]->rank > tree[yRep]->rank) {
        tree[yRep]->parent = xRep;
    } else {
        tree[xRep]->parent = yRep;
    }
    return;
}

int main() {
    int i, q, c, x, y;
    cin >> n >> q;
    for(i = 0; i < q; i++) {
        cin >> c >> x >> y;
        if(c == 0) {
            unite(x, y);
        } else {
            if(findSet(x) == findSet(y)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
