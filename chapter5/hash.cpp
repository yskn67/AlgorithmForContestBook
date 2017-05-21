#include <iostream>
#define SIZE 22369620
using namespace std;

bool h[22369620];

int getChar(char c) {
    if(c == 'A') return 1;
    else if(c == 'C') return 2;
    else if(c == 'G') return 3;
    else if(c == 'T') return 4;
    else return 0;
}

int getHash(string S) {
    int h = 0, p = 1;
    for(int i = 0; i < S.size(); i++) {
        h += p * getChar(S[i]);
        p *= 4;
    }
    return h - 1;
}

int main() {
    for(int i = 0; i < SIZE; i++) h[i] = false;
    int n;
    string instruction, s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> instruction >> s;
        if(instruction == "insert") h[getHash(s)] = true;
        else if(instruction == "find") {
            if(h[getHash(s)]) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}

