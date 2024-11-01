# LC #1 — Two Sum
# Difficulty : Easy
# Pattern    : Hash Map (one-pass)
# Time       : O(n)
# Space      : O(n)

"""
Approach:
    Iterate through the array. For each element, check if its complement
    (target - num) is already in the hash map. If yes, we found our pair.
    Otherwise, store the current element and its index.

    Key insight: we never use the same element twice because we only check
    elements we've already PASSED, not the current one.
"""

from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen: dict[int, int] = {}  # value -> index
        for i, num in enumerate(nums):
            complement = target - num
            if complement in seen:
                return [seen[complement], i]
            seen[num] = i
        return []  # problem guarantees exactly one solution


if __name__ == "__main__":
    sol = Solution()

    # Test 1
    assert sol.twoSum([2, 7, 11, 15], 9) == [0, 1]

    # Test 2: answer not at start
    assert sol.twoSum([3, 2, 4], 6) == [1, 2]

    # Test 3: same value, different indices
    assert sol.twoSum([3, 3], 6) == [0, 1]

    # Test 4: negative numbers
    assert sol.twoSum([-1, -2, -3, -4, -5], -8) == [2, 4]

    print("All tests passed!")
