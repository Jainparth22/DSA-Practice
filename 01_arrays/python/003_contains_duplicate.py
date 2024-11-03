# LC #217 — Contains Duplicate
# Difficulty : Easy
# Pattern    : Hash Set
# Time       : O(n)
# Space      : O(n)

"""
Approach:
    Use a set to track elements we've seen.
    As soon as we encounter an element that's already in the set, return True.
    If we finish the loop without a hit, return False.

    Alternative: len(nums) != len(set(nums)) — one-liner but reads whole array first.
"""

from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen: set[int] = set()
        for n in nums:
            if n in seen:
                return True
            seen.add(n)
        return False


if __name__ == "__main__":
    sol = Solution()

    assert sol.containsDuplicate([1, 2, 3, 1]) is True
    assert sol.containsDuplicate([1, 2, 3, 4]) is False
    assert sol.containsDuplicate([1, 1, 1, 3, 3, 4, 3, 2, 4, 2]) is True
    assert sol.containsDuplicate([]) is False
    assert sol.containsDuplicate([1]) is False

    print("All tests passed!")
