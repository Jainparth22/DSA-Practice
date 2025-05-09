# LC#35 — Search Insert Position
# Difficulty: Easy | Pattern: Lower Bound | Time: O(log n) | Space: O(1)
import bisect

def search_insert(a, t): return bisect.bisect_left(a, t)

assert [search_insert([1,3,5,6], x) for x in (5, 2, 7)] == [2, 1, 4]
