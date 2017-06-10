#include <iostream>
#include <algorithm>
using namespace std;

static const int INF = (1 << 31) - 1;

int mcm(int p[], int n) {
    int l, i, j, k;
    int m[n+1][n+1];
    for(i = 1; i <= n; i++) m[i][i] = 0;

    for(l = 2; l <= n; l++) {
        for(i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INF;
            for(k = i; k < j; k++) {
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]);
            }
        }
    }
    return m[1][n];
}

int main() {
    int n, r, c, i;
    cin >> n;
    int p[n+1];
    for(i = 0; i < n; i++) {
        cin >> r >> c;
        p[i] = r;
    }
    p[i] = c;
    cout << mcm(p, n) << endl;
    return 0;
}
