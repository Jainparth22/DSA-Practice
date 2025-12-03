# LC#45 — Jump Game II
# Difficulty: Medium
# Pattern: Greedy (BFS levels)
# Time: O(n) | Space: O(1)
#
# Approach:
#   Treat each "jump count" as a BFS level.
#   current_end: rightmost index reachable in current level.
#   farthest: rightmost index reachable from current level.
#   When we exhaust the current level, make a jump and start the next level.

class Solution:
    def jump(self, nums: list[int]) -> int:
        jumps = 0
        current_end = 0
        farthest = 0
        for i in range(len(nums) - 1):
            farthest = max(farthest, i + nums[i])
            if i == current_end:
                jumps += 1
                current_end = farthest
        return jumps


if __name__ == "__main__":
    s = Solution()
    assert s.jump([2, 3, 1, 1, 4]) == 2
    assert s.jump([2, 3, 0, 1, 4]) == 2
    assert s.jump([1, 2, 3]) == 2
    assert s.jump([1]) == 0
    print("All tests passed!")
