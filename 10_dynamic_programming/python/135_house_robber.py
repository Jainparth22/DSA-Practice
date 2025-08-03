# LC #198 — House Robber
# Difficulty : Medium
# Pattern    : Dynamic Programming (1D)
# Time       : O(n)   Space: O(1)

"""
dp[i] = max(dp[i-1], dp[i-2] + nums[i])
Space-optimized: only need prev1 and prev2.
"""

from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        prev2 = prev1 = 0
        for n in nums:
            prev2, prev1 = prev1, max(prev1, prev2 + n)
        return prev1


if __name__ == "__main__":
    sol = Solution()
    assert sol.rob([1, 2, 3, 1])    == 4
    assert sol.rob([2, 7, 9, 3, 1]) == 12
    assert sol.rob([1])             == 1
    assert sol.rob([2, 1, 1, 2])    == 4
    assert sol.rob([0])             == 0
    print("All tests passed!")
