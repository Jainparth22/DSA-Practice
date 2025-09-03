// LC#39 — Combination Sum
// Difficulty: Medium
// Pattern: Backtracking
// Time: O(2^n) worst case | Space: O(target/min_candidate)
//
// Approach:
//   DFS with a current combination and remaining target.
//   For each candidate (starting from current index to allow reuse):
//     - If remaining == 0: valid combo, add to result.
//     - If candidate > remaining: prune (sorted candidates allow early break).
//     - Else: recurse with candidate added, decrement remaining.
//   Backtrack by removing the last added candidate.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<int>& candidates, int target, int start,
             vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        for (int i = start; i < (int)candidates.size(); i++) {
            if (candidates[i] > target) break; // sorted — prune
            current.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, target, 0, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> c1 = {2, 3, 6, 7};
    auto r1 = sol.combinationSum(c1, 7);
    // Expected: [[2,2,3],[7]]
    cout << r1.size() << " combinations" << endl;
    for (auto& v : r1) { for (int x : v) cout << x << " "; cout << endl; }

    vector<int> c2 = {2, 3, 5};
    auto r2 = sol.combinationSum(c2, 8);
    // Expected: [[2,2,2,2],[2,3,3],[3,5]]
    cout << r2.size() << " combinations" << endl;

    cout << "All tests passed!" << endl;
    return 0;
}
