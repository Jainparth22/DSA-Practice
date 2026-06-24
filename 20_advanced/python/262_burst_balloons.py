# LC#312 — Burst Balloons
# Difficulty: Hard | Pattern: Interval DP | Time: O(n^3) | Space: O(n^2)
def max_coins(nums):
    a = [1] + nums + [1]; n = len(a); dp = [[0] * n for _ in range(n)]
    for length in range(2, n):
        for l in range(n - length):
            r = l + length
            dp[l][r] = max(dp[l][k] + dp[k][r] + a[l] * a[k] * a[r] for k in range(l + 1, r))
    return dp[0][n-1]

assert max_coins([3,1,5,8]) == 167 and max_coins([1,5]) == 10
