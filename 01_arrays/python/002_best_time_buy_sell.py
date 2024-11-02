# LC #121 — Best Time to Buy and Sell Stock
# Difficulty : Easy
# Pattern    : Greedy / One-pass
# Time       : O(n)
# Space      : O(1)

"""
Approach:
    Keep track of the minimum price seen so far.
    At each day, the best we can do is sell at today's price after buying at
    the historical minimum. Update maxProfit accordingly.

    We update minPrice BEFORE potentially updating maxProfit — so we never
    "sell before buying" in the same iteration.
"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = float('inf')
        max_profit = 0
        for price in prices:
            if price < min_price:
                min_price = price
            else:
                max_profit = max(max_profit, price - min_price)
        return max_profit


if __name__ == "__main__":
    sol = Solution()

    assert sol.maxProfit([7, 1, 5, 3, 6, 4]) == 5  # buy 1, sell 6
    assert sol.maxProfit([7, 6, 4, 3, 1]) == 0      # no profit possible
    assert sol.maxProfit([2, 4, 1]) == 2             # buy 2, sell 4
    assert sol.maxProfit([1]) == 0                   # single element
    assert sol.maxProfit([2, 1, 2, 1, 0, 1, 2]) == 2

    print("All tests passed!")
