#include <iostream>
using namespace std;
#define MAX 25
#define NIL -1

struct Node { int l, r; };

Node T[MAX];
int n;

void preorder(int u) {
    if(u == NIL) return;
    cout << " " << u;
    preorder(T[u].l);
    preorder(T[u].r);
    return;
}

void inorder(int u) {
    if(u == NIL) return;
    inorder(T[u].l);
    cout << " " << u;
    inorder(T[u].r);
    return;
}

void postorder(int u) {
    if(u == NIL) return;
    postorder(T[u].l);
    postorder(T[u].r);
    cout << " " << u;
    return;
}

int main() {
    int i, u, l, r;
    cin >> n;
    for(i = 0; i < n; i++) T[i].l = T[i].r = NIL;

    for(i = 0; i < n; i++) {
        cin >> u >> l >> r;
        T[u].l = l;
        T[u].r = r;
    }

    cout << "Preorder" << endl;
    preorder(0);
    cout << endl;
    cout << "Inorder" << endl;
    inorder(0);
    cout << endl;
    cout << "Postorder" << endl;
    postorder(0);
    cout << endl;
    return 0;
}
