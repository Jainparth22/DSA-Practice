/*
 * LC #53 — Maximum Subarray
 * Difficulty : Medium
 * Pattern    : Kadane's Algorithm (DP)
 * Time       : O(n)
 * Space      : O(1)
 *
 * Approach:
 *   dp[i] = max subarray sum ENDING at index i
 *   dp[i] = max(nums[i], dp[i-1] + nums[i])
 *   "If previous sum is negative, start fresh at nums[i]"
 *   Track global maximum across all i.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int best = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            cur  = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};

int main() {
    Solution sol;

    vector<int> n1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol.maxSubArray(n1) << "\n"; // 6  ([4,-1,2,1])

    vector<int> n2 = {1};
    cout << sol.maxSubArray(n2) << "\n"; // 1

    vector<int> n3 = {5, 4, -1, 7, 8};
    cout << sol.maxSubArray(n3) << "\n"; // 23

    vector<int> n4 = {-3, -2, -1};
    cout << sol.maxSubArray(n4) << "\n"; // -1 (least negative)

    return 0;
}
