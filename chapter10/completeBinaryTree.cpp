#include <iostream>
using namespace std;

int main() {
    int H;
    cin >> H;
    int A[H+1];
    for(int i = 1; i <= H; i++) cin >> A[i];
    for(int i = 1; i <= H; i++) {
        cout << "node " << i << ": ";
        cout << "key = " << A[i] << ", ";
        if(i != 1) cout << "parent key = " << A[i / 2] << ", ";
        if(i * 2 <= H) cout << "left key = " << A[i * 2] << ", ";
        if(i * 2 + 1 <= H) cout << "right key = " << A[i * 2 + 1] << ", ";
        cout << endl;
    }
    return 0;
}
