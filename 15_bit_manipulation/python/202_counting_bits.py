# LC#338 — Counting Bits
# Difficulty: Easy | Pattern: DP on bits | Time: O(n) | Space: O(n)
def count_bits(n):
    r = [0] * (n + 1)
    for i in range(1, n + 1): r[i] = r[i >> 1] + (i & 1)
    return r

assert count_bits(5) == [0,1,1,2,1,2]
