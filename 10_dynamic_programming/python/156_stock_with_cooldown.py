# LC#309 — Best Time to Buy/Sell with Cooldown
# Difficulty: Medium | Pattern: State Machine DP | Time: O(n) | Space: O(1)
def max_profit(p):
    hold, sold, rest = float("-inf"), 0, 0
    for x in p:
        prev_sold = sold
        sold = hold + x; hold = max(hold, rest - x); rest = max(rest, prev_sold)
    return max(sold, rest)

assert max_profit([1,2,3,0,2]) == 3
