/*
 * LC #198 — House Robber
 * Difficulty : Medium
 * Pattern    : Dynamic Programming (1D)
 * Time       : O(n)
 * Space      : O(1) — space-optimized
 *
 * Recurrence:
 *   dp[i] = max money robbing houses 0..i
 *   dp[i] = max(dp[i-1],           // skip house i
 *               dp[i-2] + nums[i]) // rob house i (can't rob i-1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int prev2 = 0, prev1 = 0;
        for (int n : nums) {
            int cur = max(prev1, prev2 + n);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

int main() {
    Solution sol;
    vector<int> n1 = {1, 2, 3, 1};  cout << sol.rob(n1) << "\n"; // 4
    vector<int> n2 = {2, 7, 9, 3, 1}; cout << sol.rob(n2) << "\n"; // 12
    vector<int> n3 = {1};            cout << sol.rob(n3) << "\n"; // 1
    vector<int> n4 = {2, 1, 1, 2};  cout << sol.rob(n4) << "\n"; // 4
    return 0;
}
