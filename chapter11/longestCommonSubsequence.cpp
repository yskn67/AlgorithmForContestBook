#include <iostream>
using namespace std;

int lcs(string X, string Y) {
    int i, j;
    int m = X.size();
    int n = Y.size();
    int c[m+1][n+1];
    c[0][0] = 0;
    for(i = 1; i <= m; i++) c[i][0] = 0;
    for(j = 1; j <= n; j++) c[0][j] = 0;
    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if(X[i-1] == Y[j-1]) c[i][j] = c[i-1][j-1] + 1;
            else if(c[i-1][j] > c[i][j-1]) c[i][j] = c[i-1][j];
            else c[i][j] = c[i][j-1];
        }
    }
    return c[m][n];
}

int main() {
    int q;
    string X, Y;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> X >> Y;
        cout << lcs(X, Y) << endl;
    }
    return 0;
}
