#include <iostream>
using namespace std;

int S[100];
int top = 0;

void push(int x) {
    S[top++] = x;
}

int pop() {
    return S[--top];
}

int main() {
    int a, b;
    string s;
    for(;;) {
        cin >> s;
        if(cin.eof()) break;
        if(s == "+") {
            b = pop();
            a = pop();
            push(a+b);
        } else if(s == "-") {
            b = pop();
            a = pop();
            push(a-b);
        } else if(s == "*") {
            b = pop();
            a = pop();
            push(a*b);
        } else {
            int n = stoi(s);
            push(n);
        }
    }
    cout << S[0] << endl;
    return 0;
}
