# LC#560 — Subarray Sum Equals K
# Difficulty: Medium
# Pattern: Prefix Sum + Hash Map
# Time: O(n) | Space: O(n)
#
# Approach:
#   Maintain a running prefix sum.
#   At each index, check if (prefix_sum - k) exists in seen counts.
#   That tells us how many subarrays ending here sum to k.

from collections import defaultdict


class Solution:
    def subarraySum(self, nums: list[int], k: int) -> int:
        prefix_count = defaultdict(int)
        prefix_count[0] = 1
        running_sum = 0
        count = 0
        for num in nums:
            running_sum += num
            count += prefix_count[running_sum - k]
            prefix_count[running_sum] += 1
        return count


if __name__ == "__main__":
    s = Solution()
    assert s.subarraySum([1, 1, 1], 2) == 2
    assert s.subarraySum([1, 2, 3], 3) == 2
    assert s.subarraySum([-1, -1, 1], -1) == 3
    print("All tests passed!")
