#include <iostream>
using namespace std;

int isIn(int T[], int q, int s) {
    for(int i = 0; i < q; i++) {
        if(T[i] == s) return 1;
    }
    return 0;
}

int main() {
    int n, q;
    cin >> n;
    int S[n];
    for(int i = 0; i < n; i++) cin >> S[i];
    cin >> q;
    int T[q];
    for(int i = 0; i < q; i++) cin >> T[i];
    int num = 0;
    for(int i = 0; i < n; i++) {
        num += isIn(T, q, S[i]);
    }
    cout << num << endl;
    return 0;
}
