# LC #746 — Min Cost Climbing Stairs
# Difficulty : Easy
# Pattern    : Dynamic Programming
# Time       : O(n)
# Space      : O(1)

"""
Recurrence: dp[i] = cost[i] + min(dp[i-1], dp[i-2])
Answer: min(dp[n-1], dp[n-2])  — can reach top from either last step

We can start at index 0 or 1 for free.
"""

from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        prev2 = cost[0]  # dp[i-2]
        prev1 = cost[1]  # dp[i-1]
        for i in range(2, n):
            curr = cost[i] + min(prev1, prev2)
            prev2, prev1 = prev1, curr
        return min(prev1, prev2)


if __name__ == "__main__":
    sol = Solution()

    assert sol.minCostClimbingStairs([10, 15, 20]) == 15
    assert sol.minCostClimbingStairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]) == 6
    assert sol.minCostClimbingStairs([0, 0, 0, 0]) == 0
    assert sol.minCostClimbingStairs([1, 2]) == 1   # start at index 1

    print("All tests passed!")
