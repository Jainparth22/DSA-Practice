# LC#1335 — Minimum Difficulty of a Job Schedule
# Difficulty: Hard | Pattern: DP | Time: O(d * n^2) | Space: O(n)
def min_difficulty(jobs, d):
    n = len(jobs)
    if n < d: return -1
    INF = float("inf"); dp = [0] + [INF] * n
    for day in range(1, d + 1):
        nd = [INF] * (n + 1)
        for i in range(day, n + 1):
            mx = 0
            for k in range(i, day - 1, -1):
                mx = max(mx, jobs[k-1]); nd[i] = min(nd[i], dp[k-1] + mx)
        dp = nd
    return dp[n]

assert min_difficulty([6,5,4,3,2,1], 2) == 7 and min_difficulty([9,9,9], 4) == -1 and min_difficulty([1,1,1], 3) == 3
