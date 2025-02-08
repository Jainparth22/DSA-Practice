# LC#904 — Fruit Into Baskets
# Difficulty: Medium | Pattern: Sliding Window + Map | Time: O(n) | Space: O(1)
from collections import defaultdict

def total_fruit(f):
    cnt = defaultdict(int); l = best = 0
    for r, x in enumerate(f):
        cnt[x] += 1
        while len(cnt) > 2:
            cnt[f[l]] -= 1
            if cnt[f[l]] == 0: del cnt[f[l]]
            l += 1
        best = max(best, r - l + 1)
    return best

assert total_fruit([1,2,3,2,2]) == 4
