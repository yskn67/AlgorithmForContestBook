#include <iostream>
#include <vector>
using namespace std;

vector<int> G;

long long insertionSort(int A[], int N, int g) {
    long long cnt = 0;
    for(int i = g; i < N; i++) {
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
    return cnt;
}

long long shellSort(int A[], int N) {
    long long cnt = 0;
    for(int h = 1; ; ) {
        if(h > N) break;
        G.push_back(h);
        h = 3 * h + 1;
    }

    for(int i = G.size()-1; i >= 0; i--) {
        cnt += insertionSort(A, N, G[i]);
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    int cnt = shellSort(A, N);

    cout << G.size() << endl;
    for(int i = G.size()-1; i >= 0; i--) {
        if(i != G.size()-1) cout << " ";
        cout << G[i];
    }
    cout << endl;
    cout << cnt << endl;
    for(int i = 0; i < N; i++) cout << A[i] << endl;
    return 0;
}
