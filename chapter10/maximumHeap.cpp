#include <iostream>
using namespace std;

int parent(int i) { return i / 2; }
int left(int i) { return i * 2; }
int right(int i) { return i * 2 + 1; }

void maxHeapify(int A[], int H, int i) {
    int l = left(i);
    int r = right(i);

    int largest = i;
    if(l <= H && A[l] > A[largest]) largest = l;
    if(r <= H && A[r] > A[largest]) largest = r;

    if(largest != i) {
        int tmp = A[largest];
        A[largest] = A[i];
        A[i] = tmp;
        maxHeapify(A, H, largest);
    }
    return;
}

void buildMaxHeap(int A[], int H) {
    for(int i = parent(H); i >= 1; i--) maxHeapify(A, H, i);
    return;
}

int main() {
    int H;
    cin >> H;
    int A[H+1];
    for(int i = 1; i <= H; i++) cin >> A[i];
    buildMaxHeap(A, H);
    for(int i = 1; i <= H; i++) cout << " " << A[i];
    cout << endl;
    return 0;
}
