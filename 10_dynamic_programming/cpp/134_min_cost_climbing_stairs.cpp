/*
 * LC #746 — Min Cost Climbing Stairs
 * Difficulty : Easy
 * Pattern    : Dynamic Programming
 * Time       : O(n)
 * Space      : O(1)
 *
 * Recurrence:
 *   dp[i] = cost[i] + min(dp[i-1], dp[i-2])
 *   "Pay cost[i] to step on stair i, then choose cheaper of two ways to reach i."
 *
 * We can start from index 0 or index 1.
 * Answer = min(dp[n-1], dp[n-2]).
 *
 * Space optimization: only need last two dp values.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0]; // dp[i-2]
        int prev1 = cost[1]; // dp[i-1]
        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2); // can reach top from last or second-last
    }
};

int main() {
    Solution sol;

    vector<int> c1 = {10, 15, 20};
    cout << sol.minCostClimbingStairs(c1) << "\n"; // 15

    vector<int> c2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << sol.minCostClimbingStairs(c2) << "\n"; // 6

    vector<int> c3 = {0, 0, 0, 0};
    cout << sol.minCostClimbingStairs(c3) << "\n"; // 0

    return 0;
}
