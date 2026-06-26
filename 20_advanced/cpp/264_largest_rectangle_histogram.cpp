// LC#84 — Largest Rectangle in Histogram
// Difficulty: Hard | Pattern: Monotonic Stack | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& h) {
    h.push_back(0); stack<int> st; int best = 0;
    for (int i = 0; i < (int)h.size(); i++) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            int ht = h[st.top()]; st.pop();
            int left = st.empty() ? -1 : st.top();
            best = max(best, ht * (i - left - 1));
        }
        st.push(i);
    }
    h.pop_back(); return best;
}
int main() { vector<int> h = {2,1,5,6,2,3}; cout << largestRectangleArea(h) << endl; } // 10
