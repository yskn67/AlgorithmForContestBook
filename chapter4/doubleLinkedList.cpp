#include <iostream>
#define MAX 1000000
using namespace std;

typedef struct Element {
    struct Element *prev;
    int key;
    struct Element *next;
} E;

E *head;
E *tail;

void insert(int key) {
    E *ep = new E();
    ep->key = key;
    if(head == NULL && tail == NULL) {
        head = ep;
        tail = ep;
    } else {
        ep->next = head;
        head->prev = ep;
        head = ep;
    }
}

void deleteFirst() {
    if(head != NULL) {
        struct Element *p = head;
        head = head->next;
        head->prev = NULL;
        delete p;
    }
}

void deleteLast() {
    if(tail != NULL) {
        struct Element *p = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete p;
    }
}

void deleteKey(int key) {
    struct Element *p = head;
    while(p != NULL) {
        if(p->key == key) {
            if(p == head) head = p->next;
            if(p == tail) tail = p->prev;
            if(p->next != NULL) p->next->prev = p->prev;
            if(p->prev != NULL) p->prev->next = p->next;
            delete p;
            return;
        }
        p = p->next;
    }
}

void printList() {
    struct Element *p = head;
    while(p != NULL) {
        cout << p->key << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int n, x;
    string command;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> command;
        if(command == "insert") {
            cin >> x;
            insert(x);
        } else if(command == "delete") {
            cin >> x;
            deleteKey(x);
        } else if(command == "deleteFirst") {
            deleteFirst();
        } else if(command == "deleteLast") {
            deleteLast();
        }
    }
    printList();
    return 0;
}
