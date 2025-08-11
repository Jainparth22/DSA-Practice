# LC #300 — Longest Increasing Subsequence
# Difficulty : Medium
# Pattern    : DP O(n²) / Patience Sort O(n log n)
# Time       : O(n log n)   Space: O(n)

"""
Patience sort approach:
  tails[i] = smallest tail element of increasing subsequence of length i+1.
  Binary search to find where to place/replace current element.
  len(tails) = LIS length.

Why it works: tails is always sorted. We binary search for leftmost position
where tails[pos] >= nums[i], replace it with nums[i] (or append if pos == len).
This keeps tails as small as possible to allow longer sequences later.
"""

from typing import List
import bisect


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tails: List[int] = []
        for n in nums:
            pos = bisect.bisect_left(tails, n)
            if pos == len(tails):
                tails.append(n)
            else:
                tails[pos] = n
        return len(tails)

    # O(n²) for understanding
    def lengthOfLIS_n2(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1] * n
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)


if __name__ == "__main__":
    sol = Solution()
    for fn in [sol.lengthOfLIS, sol.lengthOfLIS_n2]:
        assert fn([10, 9, 2, 5, 3, 7, 101, 18]) == 4
        assert fn([0, 1, 0, 3, 2, 3]) == 4
        assert fn([7, 7, 7, 7, 7, 7, 7]) == 1
        assert fn([1]) == 1
        assert fn([1, 2, 3, 4, 5]) == 5
        assert fn([5, 4, 3, 2, 1]) == 1
    print("All tests passed!")
