# LC#1340 — Jump Game V
# Difficulty: Hard | Pattern: Memoized DFS | Time: O(n * d) | Space: O(n)
from functools import lru_cache

def max_jumps(a, d):
    n = len(a)
    @lru_cache(None)
    def dfs(i):
        best = 1
        for step in (-1, 1):
            j = i + step
            while 0 <= j < n and abs(j - i) <= d and a[j] < a[i]:
                best = max(best, 1 + dfs(j)); j += step
        return best
    return max(dfs(i) for i in range(n))

assert max_jumps([6,4,14,6,8,13,9,7,10,6,12], 2) == 4 and max_jumps([3,3,3,3,3], 3) == 1
