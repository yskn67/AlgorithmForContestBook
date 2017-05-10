#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 20001
using namespace std;

int main() {
    int score = 0;
    int pos;
    stack<int> state;
    stack<pair<int, int> > state2;
    char field[MAX];
    cin >> field;
    for(int i = 0; field[i] != '\0'; i++) {
        if(field[i] == '\\') {
            state.push(i);
        } else if(field[i] == '/') {
            if(!state.empty()) {
                pos = state.top();
                score += i - pos;
                state.pop();
                int a = i - pos;
                while(!state2.empty() && state2.top().first > pos) {
                    a += state2.top().second;
                    state2.pop();
                }
                state2.push(make_pair(pos, a));
            }
        }
    }
    vector<int> ans;
    while(!state2.empty()) {
        ans.push_back(state2.top().second);
        state2.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << score << endl;
    cout << ans.size();
    for(int i = 0; i < ans.size(); i++) cout << " " << ans[i];
    cout << endl;
    return 0;
}
