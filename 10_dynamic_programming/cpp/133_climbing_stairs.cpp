/*
 * LC #70 — Climbing Stairs
 * Difficulty : Easy
 * Pattern    : Dynamic Programming (Fibonacci variant)
 * Time       : O(n)
 * Space      : O(1)  — space-optimized, only keep last two states
 *
 * Recurrence:
 *   dp[i] = dp[i-1] + dp[i-2]
 *   "To reach step i, you either came from step i-1 (1 step) or step i-2 (2 steps)."
 *
 * Base cases: dp[1] = 1, dp[2] = 2
 * This is exactly Fibonacci shifted by one.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1; // dp[i-2]
        int prev1 = 2; // dp[i-1]
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;

    cout << sol.climbStairs(1) << "\n"; // 1
    cout << sol.climbStairs(2) << "\n"; // 2
    cout << sol.climbStairs(3) << "\n"; // 3
    cout << sol.climbStairs(4) << "\n"; // 5
    cout << sol.climbStairs(5) << "\n"; // 8
    cout << sol.climbStairs(10) << "\n"; // 89
    cout << sol.climbStairs(45) << "\n"; // 1836311903

    return 0;
}
