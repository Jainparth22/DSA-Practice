# LC#714 — Best Time to Buy/Sell with Fee
# Difficulty: Medium | Pattern: State Machine DP | Time: O(n) | Space: O(1)
def max_profit(p, fee):
    cash, hold = 0, -p[0]
    for x in p:
        cash = max(cash, hold + x - fee); hold = max(hold, cash - x)
    return cash

assert max_profit([1,3,2,8,4,9], 2) == 8
