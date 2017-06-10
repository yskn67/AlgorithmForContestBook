#include <iostream>
using namespace std;

int fibo(int n) {
    if(n == 0 || n == 1) return 1;
    int n_2 = 1;
    int n_1 = 1;
    int res;
    for(int i = 2; i <= n; i++) {
        res = n_2 + n_1;
        n_2 = n_1;
        n_1 = res;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}
