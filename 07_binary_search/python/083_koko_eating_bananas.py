# LC #875 — Koko Eating Bananas
# Difficulty : Medium
# Pattern    : Binary Search on Answer
# Time       : O(n log m)   Space: O(1)

"""
Binary search for minimum eating speed k in [1, max(piles)].
feasible(k) = can finish all piles in <= h hours at speed k.
"""

from typing import List
import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def feasible(speed: int) -> bool:
            return sum(math.ceil(p / speed) for p in piles) <= h

        lo, hi = 1, max(piles)
        while lo < hi:
            mid = (lo + hi) // 2
            if feasible(mid):
                hi = mid       # mid works, try smaller
            else:
                lo = mid + 1   # too slow
        return lo


if __name__ == "__main__":
    sol = Solution()
    assert sol.minEatingSpeed([3, 6, 7, 11], 8) == 4
    assert sol.minEatingSpeed([30, 11, 23, 4, 20], 5) == 30
    assert sol.minEatingSpeed([30, 11, 23, 4, 20], 6) == 23
    assert sol.minEatingSpeed([1, 1, 1, 999999999], 10) == 142857143
    print("All tests passed!")
