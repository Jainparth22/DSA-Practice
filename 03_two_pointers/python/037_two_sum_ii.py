# LC#167 — Two Sum II
# Difficulty: Medium | Pattern: Two Pointers | Time: O(n) | Space: O(1)
def two_sum(a, t):
    l, r = 0, len(a) - 1
    while l < r:
        s = a[l] + a[r]
        if s == t: return [l + 1, r + 1]
        if s < t: l += 1
        else: r -= 1
    return []

assert two_sum([2,7,11,15], 9) == [1, 2]
