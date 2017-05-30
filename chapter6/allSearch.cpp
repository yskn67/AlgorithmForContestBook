#include <iostream>
using namespace std;

bool checkEquals(int now, int num, int ary[], int target, int score) {
    if(score + ary[now] == target) return true;
    if(now + 1 > num) return false;
    bool ret1 = checkEquals(now + 1, num, ary, target, score + ary[now]);
    bool ret2 = checkEquals(now + 1, num, ary, target, score);
    return (ret1 || ret2);
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++) cin >> A[i];
    int q;
    cin >> q;
    int m[q];
    for(int i = 0; i < q; i++) cin >> m[i];

    for(int i = 0; i < q; i++) {
        bool ret = checkEquals(0, n, A, m[i], 0);
        if(ret) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
