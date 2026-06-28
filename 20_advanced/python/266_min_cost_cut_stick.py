# LC#1547 — Minimum Cost to Cut a Stick
# Difficulty: Hard | Pattern: Interval DP | Time: O(n^3) | Space: O(n^2)
def min_cost(n, cuts):
    c = sorted([0] + cuts + [n]); m = len(c); dp = [[0] * m for _ in range(m)]
    for length in range(2, m):
        for i in range(m - length):
            j = i + length
            dp[i][j] = min(dp[i][k] + dp[k][j] for k in range(i + 1, j)) + c[j] - c[i]
    return dp[0][m-1]

assert min_cost(7, [1,3,4,5]) == 16 and min_cost(9, [5,6,1,4,2]) == 22
