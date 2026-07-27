# LC#115 — Distinct Subsequences
# Difficulty: Hard | Pattern: 1D DP | Time: O(mn) | Space: O(n)
def num_distinct(s, t):
    dp = [1] + [0] * len(t)
    for c in s:
        for j in range(len(t), 0, -1):
            if c == t[j-1]: dp[j] += dp[j-1]
    return dp[-1]

assert num_distinct("rabbbit", "rabbit") == 3 and num_distinct("babgbag", "bag") == 5
