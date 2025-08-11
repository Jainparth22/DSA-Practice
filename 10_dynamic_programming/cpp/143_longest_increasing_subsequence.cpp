/*
 * LC #300 — Longest Increasing Subsequence
 * Difficulty : Medium
 * Pattern    : DP — O(n²), or patience sorting O(n log n)
 * Time       : O(n log n) with patience sort
 * Space      : O(n)
 *
 * Approach A — O(n²):
 *   dp[i] = LIS length ending at index i
 *   dp[i] = max(dp[j]+1) for all j < i where nums[j] < nums[i]
 *
 * Approach B — O(n log n) Patience Sorting:
 *   Maintain 'tails' array where tails[i] = smallest tail of IS of length i+1.
 *   Binary search for position to place/replace in tails.
 *   Length of tails = LIS length.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(n log n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int n : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), n);
            if (it == tails.end()) tails.push_back(n);
            else *it = n; // replace — keeps tails as small as possible
        }
        return tails.size();
    }

    // O(n^2) for reference
    int lengthOfLIS_n2(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    vector<int> n1 = {10,9,2,5,3,7,101,18}; cout << sol.lengthOfLIS(n1) << "\n"; // 4
    vector<int> n2 = {0,1,0,3,2,3};          cout << sol.lengthOfLIS(n2) << "\n"; // 4
    vector<int> n3 = {7,7,7,7,7,7,7};        cout << sol.lengthOfLIS(n3) << "\n"; // 1
    return 0;
}
