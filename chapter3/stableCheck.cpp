#include <iostream>
using namespace std;

struct Card { char suit, value; };

void bubbleSort(struct Card A[], int N) {
    int i, j;
    for(i = N-1; i > 0; i--) {
        for(j = 0; j < i; j++) {
            if(A[j].value > A[j+1].value) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

void selectionSort(struct Card A[], int N) {
    int minj;
    for(int i = 0; i < N-1; i++) {
        minj = i;
        for(int j = i; j < N; j++) {
            if(A[j].value < A[minj].value) minj = j;
        }
        if(minj != i) swap(A[i], A[minj]);
    }
}

bool isStable(struct Card A1[], struct Card A2[], int N) {
    for(int i = 0; i < N; i++) {
        if(A1[i].suit != A2[i].suit) return false;
    }
    return true;
}

void printStableStatus(bool stableStatus) {
    if(stableStatus) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
}

void printArray(struct Card A[], int N) {
    for(int i = 0; i < N; i++) {
        if(i) cout << " ";
        cout << A[i].suit << A[i].value;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    struct Card A1[N], A2[N];
    for(int i = 0; i < N; i++) {
        cin >> A1[i].suit >> A1[i].value;
        A2[i] = A1[i];
    }

    bubbleSort(A1, N);
    selectionSort(A2, N);

    printArray(A1, N);
    cout << "Stable" << endl;
    printArray(A2, N);
    bool stableStatus = isStable(A1, A2, N);
    printStableStatus(stableStatus);
    return 0;
}
