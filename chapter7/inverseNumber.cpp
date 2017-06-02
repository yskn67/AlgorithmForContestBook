#include <iostream>
#define MAX 500000
#define INF 2000000000
using namespace std;
typedef long long llong;

int L[MAX/2+2], R[MAX/2+2];

llong mergeSort(int S[], int start, int end) {
    llong cnt = 0;
    llong cnt1, cnt2;
    int num = end - start;
    if(num <= 1) return 0;
    
    int mid = start + num / 2;
    cnt1 = mergeSort(S, start, mid);
    cnt2 = mergeSort(S, mid, end);

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
            cnt += mid - start - idxL;
        } else {
            S[i] = L[idxL++];
        }
    }

    return cnt + cnt1 + cnt2;
}

int main() {
    int n, S[MAX];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> S[i];
    llong ans = mergeSort(S, 0, n);
    cout << ans << endl;
    return 0;
}
