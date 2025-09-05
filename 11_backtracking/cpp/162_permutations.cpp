// LC#46 — Permutations
// Difficulty: Medium
// Pattern: Backtracking
// Time: O(n! * n) | Space: O(n)
//
// Approach:
//   Use a boolean visited[] to track which elements are in current permutation.
//   At each step, try every unused element, mark it visited, recurse.
//   When current has n elements, record it. Backtrack by unmarking.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<int>& nums, vector<bool>& used,
             vector<int>& current, vector<vector<int>>& result) {
        if ((int)current.size() == (int)nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            dfs(nums, used, current, result);
            current.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        dfs(nums, used, current, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {1, 2, 3};
    auto r1 = sol.permute(v1);
    cout << r1.size() << " permutations" << endl; // 6

    vector<int> v2 = {0, 1};
    auto r2 = sol.permute(v2);
    cout << r2.size() << " permutations" << endl; // 2

    vector<int> v3 = {1};
    auto r3 = sol.permute(v3);
    cout << r3.size() << " permutations" << endl; // 1

    cout << "All tests passed!" << endl;
    return 0;
}
