#include <iostream>
using namespace std;
#define MAX 2000000000

int A[MAX+1];
int H = 0;

int parent(int i) { return i / 2; }
int left(int i) { return i * 2; }
int right(int i) { return i * 2 + 1; }

void maxHeapify(int i) {
    int l = left(i);
    int r = right(i);

    int largest = i;
    if(l <= H && A[l] > A[largest]) largest = l;
    if(r <= H && A[r] > A[largest]) largest = r;

    if(largest != i) {
        int tmp = A[largest];
        A[largest] = A[i];
        A[i] = tmp;
        maxHeapify(largest);
    }
    return;
}

int extract() {
    int r = A[1];
    A[1] = A[H--];
    maxHeapify(1);
    return r;
}

void incrementHeap(int i) {
    int j = parent(i);
    int tmp;
    while(j >= 1 && A[i] > A[j]) {
        tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        i = j;
        j = parent(i);
    }
    return;
}

void insert(int k) {
    A[++H] = k;
    incrementHeap(H);
    return;
}


int main() {
    int k;
    string inst;
    while(1) {
        cin >> inst;
        if(inst == "end") break;
        else if(inst == "insert") {
            cin >> k;
            insert(k);
        } else if(inst == "extract") {
            cout << extract() << endl;
        }
    }
    return 0;
}
