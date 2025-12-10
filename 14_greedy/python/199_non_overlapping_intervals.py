# LC#435 — Non-overlapping Intervals
# Difficulty: Medium | Pattern: Greedy sort by end | Time: O(n log n) | Space: O(1)
def erase_overlap_intervals(v):
    v.sort(key=lambda x: x[1]); cnt, end = 0, float("-inf")
    for s, e in v:
        if s >= end: end = e
        else: cnt += 1
    return cnt

assert erase_overlap_intervals([[1,2],[2,3],[3,4],[1,3]]) == 1
