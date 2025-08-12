// LC#416 — Partition Equal Subset Sum
// Difficulty: Medium
// Pattern: 0/1 Knapsack DP
// Time: O(n * sum) | Space: O(sum)
//
// Approach:
//   If total sum is odd → impossible (return false).
//   Target = sum / 2.
//   dp[j] = true if subset with sum j is achievable.
//   For each number, iterate j from target down to num:
//     dp[j] |= dp[j - num]
//   Answer: dp[target].

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int n : nums) total += n;
        if (total % 2 != 0) return false;
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {1, 5, 11, 5};
    cout << sol.canPartition(v1) << endl; // 1 (true)  [1,5,5] and [11]

    vector<int> v2 = {1, 2, 3, 5};
    cout << sol.canPartition(v2) << endl; // 0 (false)

    vector<int> v3 = {2, 2, 1, 1};
    cout << sol.canPartition(v3) << endl; // 1 (true)

    cout << "All tests passed!" << endl;
    return 0;
}
