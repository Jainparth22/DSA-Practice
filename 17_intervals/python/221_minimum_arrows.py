# LC#452 — Minimum Number of Arrows to Burst Balloons
# Difficulty: Medium | Pattern: Greedy sort by end | Time: O(n log n) | Space: O(1)
def find_min_arrow_shots(p):
    p.sort(key=lambda x: x[1]); arrows, end = 0, float("-inf")
    for s, e in p:
        if s > end: arrows += 1; end = e
    return arrows

assert find_min_arrow_shots([[10,16],[2,8],[1,6],[7,12]]) == 2
