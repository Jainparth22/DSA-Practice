// LC#155 — Min Stack
// Difficulty: Medium | Pattern: Stack of (val, min) | Time: O(1) per op | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class MinStack {
    stack<pair<int,int>> st;
public:
    void push(int v) { st.push({v, st.empty() ? v : min(v, st.top().second)}); }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};
int main() { MinStack s; s.push(-2); s.push(0); s.push(-3); cout << s.getMin(); s.pop(); cout << s.top() << s.getMin() << endl; } // -30-2
