# LC#97 — Interleaving String
# Difficulty: Hard | Pattern: 2D DP | Time: O(mn) | Space: O(n)
def is_interleave(a, b, c):
    m, n = len(a), len(b)
    if m + n != len(c): return False
    dp = [False] * (n + 1)
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0 and j == 0: dp[j] = True
            else: dp[j] = bool((i and dp[j] and a[i-1] == c[i+j-1]) or (j and dp[j-1] and b[j-1] == c[i+j-1]))
    return dp[n]

assert is_interleave("aabcc", "dbbca", "aadbbcbcac") and not is_interleave("aabcc", "dbbca", "aadbbbaccc")
