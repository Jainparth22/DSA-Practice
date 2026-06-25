# LC#664 — Strange Printer
# Difficulty: Hard | Pattern: Interval DP | Time: O(n^3) | Space: O(n^2)
def strange_printer(s):
    n = len(s)
    if not n: return 0
    dp = [[0] * n for _ in range(n)]
    for l in range(n - 1, -1, -1):
        dp[l][l] = 1
        for r in range(l + 1, n):
            dp[l][r] = dp[l][r-1] + 1
            for k in range(l, r):
                if s[k] == s[r]: dp[l][r] = min(dp[l][r], dp[l][k] + (dp[k+1][r-1] if k + 1 <= r - 1 else 0))
    return dp[0][n-1]

assert strange_printer("aaabbb") == 2 and strange_printer("aba") == 2
