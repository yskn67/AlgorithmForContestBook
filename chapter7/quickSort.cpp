#include <iostream>
#define MAX 100000
#define INF 2000000000
using namespace std;

struct Card {
    char name;
    int value;
};

Card L[MAX/2+2], R[MAX/2+2];

void mergeSort(Card S[], int start, int end) {
    int num = end - start;
    if(num <= 1) return;
    
    int mid = start + num / 2;
    mergeSort(S, start, mid);
    mergeSort(S, mid, end);

    int idxL, idxR;
    for(idxL = 0; idxL < mid - start; idxL++) {
        L[idxL].name = S[start + idxL].name;
        L[idxL].value = S[start + idxL].value;
    }
    for(idxR = 0; idxR < end - mid; idxR++) {
        R[idxR].name = S[mid + idxR].name;
        R[idxR].value = S[mid + idxR].value;
    }
    L[idxL].value = INF;
    R[idxR].value = INF;
    idxR = 0;
    idxL = 0;
    for(int i = start; i < end; i++) {
        if(L[idxL].value > R[idxR].value) {
            S[i].name = R[idxR].name;
            S[i].value = R[idxR].value;
            idxR++;
        } else {
            S[i].name = L[idxL].name;
            S[i].value = L[idxL].value;
            idxL++;
        }
    }

    return;
}

void swap(Card *p1, Card *p2) {
    Card tmp = *(p1);
    *(p1) = *(p2);
    *(p2) = tmp;
    return;
}

int partition(Card A[], int p, int r) {
    int i = p;
    for(int j = p; j < r; j++) {
        if(A[j].value <= A[r].value) {
            swap(&A[i], &A[j]);
            i++;
        }
    }
    swap(&A[i], &A[r]);
    return i;
}

void quickSort(Card A[], int p, int r) {
    if(p < r) {
        int idx = partition(A, p, r);
        quickSort(A, p, idx-1);
        quickSort(A, idx, r);
    }
    return;
}

int main() {
    int n, i;
    cin >> n;
    Card Am[n];
    Card Aq[n];
    for(i = 0; i < n; i++) {
        cin >> Aq[i].name >> Aq[i].value;
        Am[i].name = Aq[i].name;
        Am[i].value = Aq[i].value;
    }

    mergeSort(Am, 0, n);
    quickSort(Aq, 0, n-1);

    for(i = 0; i < n; i++) {
        if((Am[i].name != Aq[i].name) || (Am[i].value != Aq[i].value)) break;
    }
    if(i == n) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    for(i = 0; i < n; i++) cout << Aq[i].name << " " << Aq[i].value << endl;
    return 0;
}
