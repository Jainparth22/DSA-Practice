// LC#496 — Next Greater Element I
// Difficulty: Easy | Pattern: Monotonic Stack + Map | Time: O(n+m) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
    unordered_map<int,int> nxt; stack<int> st;
    for (int x : b) { while (!st.empty() && st.top() < x) { nxt[st.top()] = x; st.pop(); } st.push(x); }
    vector<int> res;
    for (int x : a) res.push_back(nxt.count(x) ? nxt[x] : -1);
    return res;
}
int main() { vector<int> a = {4,1,2}, b = {1,3,4,2}; for (int x : nextGreaterElement(a, b)) cout << x << " "; } // -1 3 -1
