# LC#546 — Remove Boxes
# Difficulty: Hard | Pattern: 3D Interval DP (memo) | Time: O(n^4) | Space: O(n^3)
from functools import lru_cache

def remove_boxes(boxes):
    @lru_cache(None)
    def go(l, r, k):
        if l > r: return 0
        while r > l and boxes[r] == boxes[r-1]: r -= 1; k += 1
        res = go(l, r - 1, 0) + (k + 1) ** 2
        for i in range(l, r):
            if boxes[i] == boxes[r]: res = max(res, go(l, i, k + 1) + go(i + 1, r - 1, 0))
        return res
    return go(0, len(boxes) - 1, 0)

assert remove_boxes([1,3,2,2,2,3,4,3,1]) == 23 and remove_boxes([1,1,1]) == 9
