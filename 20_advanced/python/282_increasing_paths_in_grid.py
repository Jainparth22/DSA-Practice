# LC#2328 — Number of Increasing Paths in a Grid
# Difficulty: Hard | Pattern: Memoized DFS | Time: O(mn) | Space: O(mn)
import sys
from functools import lru_cache

def count_paths(g):
    sys.setrecursionlimit(10000); R, C = len(g), len(g[0]); M = 10**9 + 7
    @lru_cache(None)
    def dfs(i, j):
        res = 1
        for a, b in ((i+1, j), (i-1, j), (i, j+1), (i, j-1)):
            if 0 <= a < R and 0 <= b < C and g[a][b] > g[i][j]: res += dfs(a, b)
        return res % M
    return sum(dfs(i, j) for i in range(R) for j in range(C)) % M

assert count_paths([[1,1],[3,4]]) == 8 and count_paths([[1],[2]]) == 3
