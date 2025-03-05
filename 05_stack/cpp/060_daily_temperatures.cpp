/*
 * LC #739 — Daily Temperatures
 * Difficulty : Medium
 * Pattern    : Monotonic Stack (Next Greater Element)
 * Time       : O(n)
 * Space      : O(n)
 *
 * Approach:
 *   Maintain a stack of indices where temperatures are DECREASING.
 *   When temperatures[i] > temperatures[stack.top()], we found
 *   the "next warmer day" for the top element.
 *   answer[popped_index] = i - popped_index
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // indices, temps in stack are DECREASING

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top(); st.pop();
                answer[idx] = i - idx;
            }
            st.push(i);
        }
        // remaining indices in stack: no future warmer day → answer stays 0
        return answer;
    }
};

int main() {
    Solution sol;

    vector<int> t1 = {73, 74, 75, 71, 69, 72, 76, 73};
    auto r1 = sol.dailyTemperatures(t1);
    // Expected: [1, 1, 4, 2, 1, 1, 0, 0]
    for (int x : r1) cout << x << " "; cout << "\n";

    vector<int> t2 = {30, 40, 50, 60};
    auto r2 = sol.dailyTemperatures(t2);
    // Expected: [1, 1, 1, 0]
    for (int x : r2) cout << x << " "; cout << "\n";

    vector<int> t3 = {30, 60, 90};
    auto r3 = sol.dailyTemperatures(t3);
    // Expected: [1, 1, 0]
    for (int x : r3) cout << x << " "; cout << "\n";

    return 0;
}
