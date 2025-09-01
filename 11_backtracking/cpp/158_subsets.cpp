/*
 * LC #78 — Subsets
 * Difficulty : Medium
 * Pattern    : Backtracking
 * Time       : O(2^n × n)
 * Space      : O(n) recursion depth
 *
 * Approach:
 *   For each element, we either INCLUDE it or SKIP it.
 *   Every recursive call adds the current 'current' to result (all prefixes are valid subsets).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int> current;

    void bt(vector<int>& nums, int start) {
        result.push_back(current); // snapshot — every state is a valid subset
        for (int i = start; i < (int)nums.size(); i++) {
            current.push_back(nums[i]);
            bt(nums, i + 1);       // i+1: each element used at most once
            current.pop_back();    // undo
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        bt(nums, 0);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> n1 = {1, 2, 3};
    auto res = sol.subsets(n1);
    // Expected: [[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]] (order may vary)
    cout << "Total subsets: " << res.size() << "\n"; // 8 = 2^3
    for (auto& s : res) {
        cout << "[";
        for (int i = 0; i < (int)s.size(); i++) cout << s[i] << (i+1<(int)s.size()?",":"");
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
