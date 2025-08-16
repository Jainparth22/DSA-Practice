# LC#63 — Unique Paths II
# Difficulty: Medium | Pattern: 1D DP with obstacles | Time: O(mn) | Space: O(n)
def unique_paths_with_obstacles(g):
    n = len(g[0]); dp = [1] + [0] * (n - 1)
    for row in g:
        for j in range(n):
            if row[j]: dp[j] = 0
            elif j: dp[j] += dp[j-1]
    return dp[-1]

assert unique_paths_with_obstacles([[0,0,0],[0,1,0],[0,0,0]]) == 2
