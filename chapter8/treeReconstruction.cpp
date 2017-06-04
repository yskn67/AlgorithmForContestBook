#include <iostream>
#include <vector>
using namespace std;

int n, pos;
vector<int> pre, in, post;

void rec(int l, int r) {
    if(l >= r) return;
    int c = pre[pos++];
    int m = distance(in.begin(), find(in.begin(), in.end(), c));
    rec(l, m);
    rec(m + 1, r);
    post.push_back(c);
    return;
}

int main() {
    int i, u;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> u;
        pre.push_back(u);
    }
    for(i = 0; i < n; i++) {
        cin >> u;
        in.push_back(u);
    }
    
    pos = 0;
    rec(0, pre.size());
    for (i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << post[i];
    }
    cout << endl;

    return 0;
}
