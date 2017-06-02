#include <iostream>
using namespace std;

int S[500000], C[500000];

int mergeSort(int start, int end) {
    int comp = 0, comp1 = 0, comp2 = 0;
    int num = end - start;
    
    if(num > 1) {
        int mid = start + num / 2;
        comp1 = mergeSort(start, mid);
        comp2 = mergeSort(mid, end);

        for(int i = start; i < end; i++) C[i] = S[i];
        int idx1 = start;
        int idx2 = mid;
        for(int i = start; i < end; i++) {
            if(idx1 >= mid) {
                while(idx2 < end) {
                    S[i++] = C[idx2++];
                    comp++;
                }
                break;
            } else if(idx2 >= end) {
                while(idx1 < mid) {
                    S[i++] = C[idx1++];
                    comp++;
                }
                break;
            } else if(C[idx1] > C[idx2]) {
                S[i] = C[idx2++];
                comp++;
            } else {
                S[i] = C[idx1++];
                comp++;
            }
        }
    }

    return comp + comp1 + comp2;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> S[i];
    int comp = mergeSort(0, n);
    for(int i = 0; i < n; i++) {
        if(i != 0) cout << " ";
        cout << S[i];
    }
    cout << endl;
    cout << comp << endl;
    return 0;
}
