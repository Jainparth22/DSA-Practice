# LC#62 — Unique Paths
# Difficulty: Medium | Pattern: 1D DP | Time: O(mn) | Space: O(n)
def unique_paths(m, n):
    dp = [1] * n
    for _ in range(1, m):
        for j in range(1, n): dp[j] += dp[j-1]
    return dp[-1]

assert unique_paths(3, 7) == 28 and unique_paths(3, 2) == 3
