# LC#152 — Maximum Product Subarray
# Difficulty: Medium
# Pattern: DP / Greedy — Track both max and min
# Time: O(n) | Space: O(1)
#
# Approach:
#   Negatives flip max↔min. Track both cur_max and cur_min.
#   At each step, candidate max = max(num, num*cur_max, num*cur_min).
#   Same for min. Update global max.

class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        cur_max = cur_min = result = nums[0]
        for num in nums[1:]:
            candidates = (num, cur_max * num, cur_min * num)
            cur_max, cur_min = max(candidates), min(candidates)
            result = max(result, cur_max)
        return result


if __name__ == "__main__":
    s = Solution()
    assert s.maxProduct([2, 3, -2, 4]) == 6
    assert s.maxProduct([-2, 0, -1]) == 0
    assert s.maxProduct([-2, 3, -4]) == 24
    assert s.maxProduct([-2]) == -2
    assert s.maxProduct([0, 2]) == 2
    print("All tests passed!")
