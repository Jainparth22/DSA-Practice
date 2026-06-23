# LC#741 — Cherry Pickup
# Difficulty: Hard | Pattern: DP on two simultaneous paths | Time: O(n^3) | Space: O(n^2)
def cherry_pickup(g):
    n = len(g); NEG = float("-inf"); dp = [[NEG] * n for _ in range(n)]; dp[0][0] = g[0][0]
    for k in range(1, 2 * n - 1):
        nd = [[NEG] * n for _ in range(n)]
        for i in range(max(0, k - n + 1), min(n - 1, k) + 1):
            for j in range(i, min(n - 1, k) + 1):
                a, b = k - i, k - j
                if g[i][a] < 0 or g[j][b] < 0: continue
                best = max(dp[pi][pj] for pi in (i, i - 1) for pj in (j, j - 1) if pi >= 0 and pj >= 0)
                if best == NEG: continue
                nd[i][j] = best + g[i][a] + (g[j][b] if i != j else 0)
        dp = nd
    return max(0, dp[n-1][n-1])

assert cherry_pickup([[0,1,-1],[1,0,-1],[1,1,1]]) == 5 and cherry_pickup([[1,1,-1],[1,-1,1],[-1,1,1]]) == 0
