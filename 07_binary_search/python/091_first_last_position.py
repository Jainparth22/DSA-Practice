# LC#34 — Find First and Last Position
# Difficulty: Medium | Pattern: Lower/Upper Bound | Time: O(log n) | Space: O(1)
import bisect

def search_range(a, t):
    lo, hi = bisect.bisect_left(a, t), bisect.bisect_right(a, t)
    return [-1, -1] if lo == hi else [lo, hi - 1]

assert search_range([5,7,7,8,8,10], 8) == [3, 4] and search_range([5,7,7,8,8,10], 6) == [-1, -1]
