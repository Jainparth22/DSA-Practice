# LC #70 — Climbing Stairs
# Difficulty : Easy
# Pattern    : Dynamic Programming (Fibonacci)
# Time       : O(n)
# Space      : O(1) for space-optimized variant

"""
Recurrence: dp[i] = dp[i-1] + dp[i-2]
Base: dp[1] = 1, dp[2] = 2

Three approaches shown below:
  1. Top-down with memoization
  2. Bottom-up tabulation
  3. Space-optimized (O(1))
"""


class Solution:
    # Approach 1: Memoization
    def climbStairs_memo(self, n: int) -> int:
        memo: dict[int, int] = {}

        def dp(i: int) -> int:
            if i <= 2:
                return i
            if i not in memo:
                memo[i] = dp(i - 1) + dp(i - 2)
            return memo[i]

        return dp(n)

    # Approach 2: Tabulation
    def climbStairs_tab(self, n: int) -> int:
        if n <= 2:
            return n
        table = [0] * (n + 1)
        table[1], table[2] = 1, 2
        for i in range(3, n + 1):
            table[i] = table[i - 1] + table[i - 2]
        return table[n]

    # Approach 3: Space-optimized (preferred)
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        prev2, prev1 = 1, 2
        for _ in range(3, n + 1):
            curr = prev1 + prev2
            prev2, prev1 = prev1, curr
        return prev1


if __name__ == "__main__":
    sol = Solution()
    for approach in [sol.climbStairs_memo, sol.climbStairs_tab, sol.climbStairs]:
        assert approach(1) == 1
        assert approach(2) == 2
        assert approach(3) == 3
        assert approach(4) == 5
        assert approach(5) == 8
        assert approach(10) == 89
        assert approach(45) == 1836311903
    print("All tests passed!")
