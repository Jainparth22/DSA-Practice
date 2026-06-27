// LC#85 — Maximal Rectangle
// Difficulty: Hard | Pattern: Histogram per row | Time: O(mn) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int hist(vector<int> h) { h.push_back(0); stack<int> st; int best = 0; for (int i = 0; i < (int)h.size(); i++) { while (!st.empty() && h[st.top()] >= h[i]) { int ht = h[st.top()]; st.pop(); best = max(best, ht * (i - (st.empty() ? -1 : st.top()) - 1)); } st.push(i); } return best; }
int maximalRectangle(vector<vector<char>>& m) {
    if (m.empty()) return 0; vector<int> h(m[0].size()); int best = 0;
    for (auto& row : m) { for (size_t j = 0; j < row.size(); j++) h[j] = row[j] == '1' ? h[j] + 1 : 0; best = max(best, hist(h)); }
    return best;
}
int main() { vector<string> s = {"10100","10111","11111","10010"}; vector<vector<char>> m; for (auto& r : s) m.push_back(vector<char>(r.begin(), r.end())); cout << maximalRectangle(m) << endl; } // 6
