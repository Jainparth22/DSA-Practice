# LC #238 — Product of Array Except Self
# Difficulty : Medium
# Pattern    : Prefix + Suffix product
# Time       : O(n)   Space: O(1) extra

"""
Two passes, no division:
  Pass 1: result[i] = product of all elements LEFT of i
  Pass 2: multiply result[i] by product of all elements RIGHT of i
"""

from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [1] * n

        prefix = 1
        for i in range(n):
            result[i] = prefix
            prefix *= nums[i]

        suffix = 1
        for i in range(n - 1, -1, -1):
            result[i] *= suffix
            suffix *= nums[i]

        return result


if __name__ == "__main__":
    sol = Solution()
    assert sol.productExceptSelf([1, 2, 3, 4]) == [24, 12, 8, 6]
    assert sol.productExceptSelf([-1, 1, 0, -3, 3]) == [0, 0, 9, 0, 0]
    assert sol.productExceptSelf([1, 1]) == [1, 1]
    print("All tests passed!")
