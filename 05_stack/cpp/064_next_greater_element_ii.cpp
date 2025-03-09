// LC#503 — Next Greater Element II
// Difficulty: Medium | Pattern: Circular Monotonic Stack | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int>& a) {
    int n = a.size(); vector<int> res(n, -1); stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
        while (!st.empty() && a[st.top()] < a[i % n]) { res[st.top()] = a[i % n]; st.pop(); }
        if (i < n) st.push(i);
    }
    return res;
}
int main() { vector<int> a = {1,2,1}; for (int x : nextGreaterElements(a)) cout << x << " "; } // 2 -1 2
