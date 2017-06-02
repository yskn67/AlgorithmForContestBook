#include <iostream>
using namespace std;

void swap(int *p1, int *p2) {
    int tmp = *(p1);
    *(p1) = *(p2);
    *(p2) = tmp;
    return;
}

int partition(int A[], int p, int r) {
    int i = p;
    for(int j = p; j < r; j++) {
        if(A[j] <= A[r]) {
            swap(&A[i], &A[j]);
            i++;
        }
    }
    swap(&A[i], &A[r]);
    return i;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    int idx = partition(A, 0, n-1);
    for (int i = 0; i < n; i++) {
        if(i != 0) cout << " ";
        if(i == idx) cout << "[" << A[i] << "]";
        else cout << A[i];
    }
    cout << endl;
    return 0;
}
