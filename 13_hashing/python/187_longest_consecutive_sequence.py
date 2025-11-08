# LC#128 — Longest Consecutive Sequence
# Difficulty: Medium
# Pattern: Hash Set
# Time: O(n) | Space: O(n)
#
# Approach:
#   Put all numbers in a set.
#   For each number that is a sequence START (num-1 not in set),
#   count how long the consecutive run is.
#   Return the maximum run length found.

class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        num_set = set(nums)
        longest = 0
        for num in num_set:
            if num - 1 not in num_set:   # start of a sequence
                current = num
                length = 1
                while current + 1 in num_set:
                    current += 1
                    length += 1
                longest = max(longest, length)
        return longest


if __name__ == "__main__":
    s = Solution()
    assert s.longestConsecutive([100, 4, 200, 1, 3, 2]) == 4
    assert s.longestConsecutive([0, 3, 7, 2, 5, 8, 4, 6, 0, 1]) == 9
    assert s.longestConsecutive([]) == 0
    print("All tests passed!")
