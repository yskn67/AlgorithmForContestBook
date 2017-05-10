#include <iostream>
using namespace std;

struct Proc {
    char name[32];
    int time;
};

const int MAX = 30000;
struct Proc Q[MAX];
int head = 0;
int tail = 0;

void enqueue(struct Proc x) {
    Q[tail++] = x;
}

struct Proc dequeue() {
    return Q[head++];
}

int main() {
    int n, q;
    int spend = 0;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        struct Proc proc;
        cin >> proc.name >> proc.time;
        enqueue(proc);
    }
    struct Proc proc;
    while(tail > head) {
        proc = dequeue();
        if(proc.time > q) {
            spend += q;
            proc.time -= q;
            enqueue(proc);
        } else {
            spend += proc.time;
            cout << proc.name << " " << spend << endl;
        }
    }
    return 0;
}
