# LC#1510 — Stone Game IV
# Difficulty: Hard | Pattern: Game DP | Time: O(n sqrt n) | Space: O(n)
def winner_square_game(n):
    dp = [False] * (n + 1)
    for i in range(1, n + 1):
        k = 1
        while k * k <= i and not dp[i]: dp[i] = not dp[i - k * k]; k += 1
    return dp[n]

assert [winner_square_game(x) for x in (1, 2, 4, 7)] == [True, False, True, False]
