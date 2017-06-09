#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *p, *l, *r;
};

Node *root, *NIL;
int n;

void preorder(Node *u) {
    if(u == NIL) return;
    cout << " " << u->key;
    preorder(u->l);
    preorder(u->r);
    return;
}

void inorder(Node *u) {
    if(u == NIL) return;
    inorder(u->l);
    cout << " " << u->key;
    inorder(u->r);
    return;
}

void insert(int z) {
    Node *ind = root;
    Node *p = NIL;
    Node *nn;
    
    nn = (Node *)malloc(sizeof(Node));
    nn->key = z;
    nn->r = NIL;
    nn->l = NIL;

    while(ind != NIL) {
        p = ind;
        if(z < ind->key) {
            ind = ind->l;
        } else {
            ind = ind->r;
        }
    }

    if(root == NIL) root = nn;
    else if(z < p->key) p->l = nn;
    else p->r = nn;

    return;
}

int main() {
    int i, k;
    string inst;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> inst;
        if(inst == "insert") {
            cin >> k;
            insert(k);
        } else if (inst == "print") {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }
    return 0;
}
