#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 1000;
static const int WMAX = 10000;

int A[MAX], B[MAX];

int solve(int n, int m) {
    int ans = 0;
    bool Done[n];
    int Dir[WMAX+1];
    for(int i = 0; i < n; i++) {
        B[i] = A[i];
        Done[i] = false;
    }
    sort(B, B+n);
    for(int i = 0; i < n; i++) Dir[B[i]] = i;
    for(int i = 0; i < n; i++) {
        if(Done[i]) continue;
        int cur = i;
        int W = 0;
        int ng = 0;
        int mg = WMAX;
        while(1) {
            Done[cur] = true;
            ng++;
            int w = A[cur];
            mg = min(mg, w);
            W += w;
            cur = Dir[w];
            if(Done[cur]) break;
        }
        ans += min(W + (ng - 2) * mg, mg + W + (ng + 1 ) * m);
    }

    return ans;
}

int main() {
    int n;
    int m = WMAX;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        m = min(m, A[i]);
    }
    int ans = solve(n, m);
    cout << ans << endl;
    return 0;
}
