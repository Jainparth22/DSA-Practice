# LC#1359 — Count All Valid Pickup and Delivery Options
# Difficulty: Hard | Pattern: Combinatorics | Time: O(n) | Space: O(1)
def count_orders(n):
    M = 10**9 + 7; r = 1
    for i in range(1, n + 1): r = r * (i * (2 * i - 1)) % M
    return r

assert [count_orders(i) for i in (1, 2, 3)] == [1, 6, 90]
