# LC #322 — Coin Change
# Difficulty : Medium
# Pattern    : DP — Unbounded Knapsack
# Time       : O(amount × coins)   Space: O(amount)

"""
dp[i] = min coins to make amount i.
For each amount i, try each coin: dp[i] = min(dp[i], dp[i-coin] + 1).
"""

from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i and dp[i - coin] != float('inf'):
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        return dp[amount] if dp[amount] != float('inf') else -1


if __name__ == "__main__":
    sol = Solution()
    assert sol.coinChange([1, 5, 10, 25], 41) == 4   # 25+10+5+1
    assert sol.coinChange([1, 2, 5], 11) == 3         # 5+5+1
    assert sol.coinChange([2], 3)        == -1
    assert sol.coinChange([1], 0)        == 0
    assert sol.coinChange([1], 1)        == 1
    assert sol.coinChange([186,419,83,408], 6249) == 20
    print("All tests passed!")
