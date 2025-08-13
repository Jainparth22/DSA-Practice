# LC#494 — Target Sum
# Difficulty: Medium | Pattern: Subset Sum DP | Time: O(n * S) | Space: O(S)
def find_target_sum_ways(a, t):
    total = sum(a)
    if abs(t) > total or (total + t) % 2: return 0
    s = (total + t) // 2; dp = [1] + [0] * s
    for x in a:
        for j in range(s, x - 1, -1): dp[j] += dp[j - x]
    return dp[s]

assert find_target_sum_ways([1,1,1,1,1], 3) == 5
