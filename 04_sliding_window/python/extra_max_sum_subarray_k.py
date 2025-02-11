# LC#643 — Maximum Average Subarray I
# Difficulty: Easy
# Pattern: Fixed Sliding Window
# Time: O(n) | Space: O(1)
#
# Approach:
#   Build sum of first k elements, then slide window right:
#   add next element, drop leftmost — track maximum sum.

class Solution:
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        window_sum = sum(nums[:k])
        max_sum = window_sum
        for i in range(k, len(nums)):
            window_sum += nums[i] - nums[i - k]
            max_sum = max(max_sum, window_sum)
        return max_sum / k


if __name__ == "__main__":
    s = Solution()
    assert abs(s.findMaxAverage([1, 12, -5, -6, 50, 3], 4) - 12.75) < 1e-5
    assert abs(s.findMaxAverage([5], 1) - 5.0) < 1e-5
    assert abs(s.findMaxAverage([0, 1, 1, 3, 3], 4) - 2.0) < 1e-5
    print("All tests passed!")
