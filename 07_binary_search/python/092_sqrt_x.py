# LC#69 — Sqrt(x)
# Difficulty: Easy | Pattern: Binary Search on answer | Time: O(log x) | Space: O(1)
def my_sqrt(x):
    l, r = 0, x
    while l < r:
        m = (l + r + 1) // 2
        if m * m <= x: l = m
        else: r = m - 1
    return l

assert my_sqrt(8) == 2 and my_sqrt(16) == 4 and my_sqrt(0) == 0
