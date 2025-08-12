# LC#416 — Partition Equal Subset Sum
# Difficulty: Medium
# Pattern: 0/1 Knapsack DP
# Time: O(n * sum) | Space: O(sum)
#
# Approach:
#   If total is odd → False. Target = total // 2.
#   dp[j] = True if subset summing to j is achievable.
#   Update in reverse to avoid using same element twice.

class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False
        target = total // 2
        dp = [False] * (target + 1)
        dp[0] = True
        for num in nums:
            for j in range(target, num - 1, -1):
                dp[j] = dp[j] or dp[j - num]
        return dp[target]


if __name__ == "__main__":
    s = Solution()
    assert s.canPartition([1, 5, 11, 5]) == True
    assert s.canPartition([1, 2, 3, 5]) == False
    assert s.canPartition([2, 2, 1, 1]) == True
    assert s.canPartition([1, 1]) == True
    print("All tests passed!")
