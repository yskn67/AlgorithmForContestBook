#include <iostream>
using namespace std;

void insertionSort(int A[], int N) {
    int i, j, v;
    for(i = 1; i < N; i++) {
        v = A[i];
        for(j = i - 1; j >= 0 && A[j] > v; j--) A[j+1] = A[j];
        A[j+1] = v;
    }
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    insertionSort(A, N);
    for(int i = 0; i < N; i++) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    return 0;
}
