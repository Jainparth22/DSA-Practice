# LC#454 — 4Sum II
# Difficulty: Medium | Pattern: Hash Map of pair sums | Time: O(n^2) | Space: O(n^2)
from collections import Counter

def four_sum_count(a, b, c, d):
    m = Counter(x + y for x in a for y in b)
    return sum(m[-(x + y)] for x in c for y in d)

assert four_sum_count([1,2], [-2,-1], [-1,2], [0,2]) == 2
