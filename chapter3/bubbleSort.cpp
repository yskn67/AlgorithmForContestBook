#include <iostream>
using namespace std;

int bubbleSort(int A[], int N) {
    int i, j;
    int sw = 0;
    for(i = N-1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(A[j] > A[j+1]) {
                swap(A[j], A[j+1]);
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];
    int sw = bubbleSort(A, N);
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}
