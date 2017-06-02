#include <iostream>
#define MAX 10000
using namespace std;

void countingSort(int A[], int B[], int n) {
    int C[MAX];
    for(int i = 0; i < MAX; i++) C[i] = 0;
    for(int i = 0; i < n; i++) C[A[i]]++;
    for(int i = 1; i < MAX; i++) C[i] = C[i] + C[i-1];
    for(int i = 0; i < n; i++) B[--C[A[i]]] = A[i];
    return;
}

int main() {
    int n;
    cin >> n;
    int A[n], B[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    countingSort(A, B, n);
    for(int i = 0; i < n; i++) {
        if(i != 0) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}
