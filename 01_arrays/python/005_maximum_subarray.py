# LC #53 — Maximum Subarray (Kadane's Algorithm)
# Difficulty : Medium
# Pattern    : Dynamic Programming / Greedy
# Time       : O(n)   Space: O(1)

"""
Kadane's: at each position i, the best subarray ending at i is either:
  - Just nums[i] (start fresh — previous running sum was dragging us down)
  - nums[i] + (best subarray ending at i-1)

Track global max across all positions.
"""

from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur = best = nums[0]
        for n in nums[1:]:
            cur  = max(n, cur + n)
            best = max(best, cur)
        return best


if __name__ == "__main__":
    sol = Solution()
    assert sol.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == 6
    assert sol.maxSubArray([1]) == 1
    assert sol.maxSubArray([5, 4, -1, 7, 8]) == 23
    assert sol.maxSubArray([-3, -2, -1]) == -1
    assert sol.maxSubArray([-2, -1]) == -1
    print("All tests passed!")
