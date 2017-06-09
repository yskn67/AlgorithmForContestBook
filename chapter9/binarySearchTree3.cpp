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
    nn->p = p;

    if(root == NIL) root = nn;
    else if(z < p->key) p->l = nn;
    else p->r = nn;

    return;
}

Node *find(int z) {
    Node *ind = root;
    while(ind != NIL && ind->key != z) {
        if(z < ind->key) ind = ind->l;
        else ind = ind->r;
    }
    return ind;
}

Node *getMinimum(Node *x) {
    while(x->l != NIL) x = x->l;
    return x;
}

Node *getSuccessor(Node *x) {
    if(x->r != NIL) return getMinimum(x->r);
    
    Node *y = x->p;
    while(y != NIL && x == y->r) {
        x = y;
        y = y->p;
    }
    return y;
}

void del(int z) {
    Node *target = find(z);
    if(target == NIL) return;

    Node *delnode;
    if(target->l == NIL || target->r == NIL) {
        delnode = target;
    } else {
        delnode = getSuccessor(target);
    }

    Node *child;
    if(delnode->l != NIL) child = delnode->l;
    else child = delnode->r;

    if(child != NIL) child->p = delnode->p;

    if(delnode->p == NIL) root = child;
    else if(delnode == delnode->p->l) delnode->p->l = child;
    else delnode->p->r = child;

    if(delnode != target) target->key = delnode->key;

    free(delnode);

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
        } else if (inst == "find") {
            cin >> k;
            Node *res = find(k);
            if(res == NIL) cout << "no" << endl;
            else cout << "yes" << endl;
        } else if (inst == "delete") {
            cin >> k;
            del(k);
        } else if (inst == "print") {
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }
    return 0;
}
