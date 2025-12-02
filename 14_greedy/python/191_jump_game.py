# LC#55 — Jump Game
# Difficulty: Medium
# Pattern: Greedy
# Time: O(n) | Space: O(1)
#
# Approach:
#   Track the farthest reachable index.
#   If current index exceeds max_reach, we can't proceed → False.
#   Update max_reach at each step and return True if we finish.

class Solution:
    def canJump(self, nums: list[int]) -> bool:
        max_reach = 0
        for i, jump in enumerate(nums):
            if i > max_reach:
                return False
            max_reach = max(max_reach, i + jump)
        return True


if __name__ == "__main__":
    s = Solution()
    assert s.canJump([2, 3, 1, 1, 4]) == True
    assert s.canJump([3, 2, 1, 0, 4]) == False
    assert s.canJump([0]) == True
    assert s.canJump([2, 0, 0]) == True
    print("All tests passed!")
