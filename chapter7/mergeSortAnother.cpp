#include <iostream>
#define MAX 500000
#define INF 2000000000
using namespace std;

int L[MAX/2+2], R[MAX/2+2];
int comp = 0;

void mergeSort(int S[], int start, int end) {
    int num = end - start;
    if(num <= 1) return;
    
    int mid = start + num / 2;
    mergeSort(S, start, mid);
    mergeSort(S, mid, end);

    int idxL, idxR;
    for(idxL = 0; idxL < mid - start; idxL++) L[idxL] = S[start + idxL];
    for(idxR = 0; idxR < end - mid; idxR++) R[idxR] = S[mid + idxR];
    L[idxL] = INF;
    R[idxR] = INF;
    idxR = 0;
    idxL = 0;
    for(int i = start; i < end; i++) {
        if(L[idxL] > R[idxR]) {
            S[i] = R[idxR++];
        } else {
            S[i] = L[idxL++];
        }
        comp++;
    }

    return;
}

int main() {
    int n, S[MAX];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> S[i];
    mergeSort(S, 0, n);
    for(int i = 0; i < n; i++) {
        if(i != 0) cout << " ";
        cout << S[i];
    }
    cout << endl;
    cout << comp << endl;
    return 0;
}
