#include <iostream>
using namespace std;

int bsearch(int S[], int n, int t) {
    int left = 0;
    int right = n;
    int now;
    while(left < right) {
        now = (right + left) / 2;
        if(S[now] == t) return 1;
        else if(S[now] > t) right = now;
        else left = now + 1;
    }
    return 0;
}

int main() {
    int n, q, t, num = 0;
    cin >> n;
    int S[n];
    for(int i = 0; i < n; i++) cin >> S[i];
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> t;
        num += bsearch(S, n, t);
    }
    cout << num << endl;
    return 0;
}
