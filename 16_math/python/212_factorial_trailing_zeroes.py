# LC#172 — Factorial Trailing Zeroes
# Difficulty: Medium | Pattern: Count factors of 5 | Time: O(log n) | Space: O(1)
def trailing_zeroes(n):
    c = 0
    while n: n //= 5; c += n
    return c

assert trailing_zeroes(5) == 1 and trailing_zeroes(100) == 24
