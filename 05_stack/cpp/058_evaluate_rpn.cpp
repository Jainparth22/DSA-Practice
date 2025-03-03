// LC#150 — Evaluate Reverse Polish Notation
// Difficulty: Medium | Pattern: Stack | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int evalRPN(vector<string>& t) {
    stack<int> st;
    for (auto& s : t) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int b = st.top(); st.pop(); int a = st.top(); st.pop();
            st.push(s == "+" ? a + b : s == "-" ? a - b : s == "*" ? a * b : a / b);
        } else st.push(stoi(s));
    }
    return st.top();
}
int main() { vector<string> t = {"2","1","+","3","*"}; cout << evalRPN(t) << endl; } // 9
