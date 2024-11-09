# LC #15 — 3Sum
# Difficulty : Medium
# Pattern    : Sort + Two Pointers
# Time       : O(n²)   Space: O(1) extra

"""
Sort first, then for each element nums[i] use two pointers on the rest.
Skip duplicates carefully to avoid duplicate triplets in output.
"""

from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)
        result = []

        for i in range(n - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue          # skip duplicate i
            if nums[i] > 0:
                break             # sorted, rest all positive → no zero sum

            l, r = i + 1, n - 1
            while l < r:
                s = nums[i] + nums[l] + nums[r]
                if s == 0:
                    result.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]: l += 1
                    while l < r and nums[r] == nums[r - 1]: r -= 1
                    l += 1; r -= 1
                elif s < 0:
                    l += 1
                else:
                    r -= 1
        return result


if __name__ == "__main__":
    sol = Solution()
    assert sorted(sol.threeSum([-1, 0, 1, 2, -1, -4])) == [[-1, -1, 2], [-1, 0, 1]]
    assert sol.threeSum([0, 1, 1]) == []
    assert sol.threeSum([0, 0, 0]) == [[0, 0, 0]]
    assert sol.threeSum([]) == []
    print("All tests passed!")
