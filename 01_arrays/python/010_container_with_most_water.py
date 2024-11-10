# LC #11 — Container With Most Water
# Difficulty : Medium
# Pattern    : Two Pointers (Greedy)
# Time       : O(n)   Space: O(1)

"""
Start with widest container (l=0, r=n-1).
Move the SHORTER wall inward — only way to potentially increase area.
(Keeping the taller wall and reducing width never helps.)
"""

from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        max_water = 0
        while l < r:
            water = min(height[l], height[r]) * (r - l)
            max_water = max(max_water, water)
            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1
        return max_water


if __name__ == "__main__":
    sol = Solution()
    assert sol.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
    assert sol.maxArea([1, 1]) == 1
    assert sol.maxArea([4, 3, 2, 1, 4]) == 16
    assert sol.maxArea([1, 2, 1]) == 2
    print("All tests passed!")
