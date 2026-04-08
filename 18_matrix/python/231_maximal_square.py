# LC#221 — Maximal Square
# Difficulty: Medium | Pattern: 2D DP | Time: O(mn) | Space: O(n)
def maximal_square(m):
    C = len(m[0]); dp = [0] * (C + 1); best = 0
    for row in m:
        prev = 0
        for j in range(1, C + 1):
            tmp = dp[j]
            dp[j] = 1 + min(dp[j], dp[j-1], prev) if row[j-1] == "1" else 0
            best = max(best, dp[j]); prev = tmp
    return best * best

assert maximal_square([list("10100"), list("10111"), list("11111"), list("10010")]) == 4
