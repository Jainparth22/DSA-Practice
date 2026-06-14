# LC#1838 — Frequency of the Most Frequent Element
# Difficulty: Medium | Pattern: Sort + Sliding Window | Time: O(n log n) | Space: O(1)
def max_frequency(a, k):
    a.sort(); s = l = best = 0
    for r, x in enumerate(a):
        s += x
        while x * (r - l + 1) - s > k: s -= a[l]; l += 1
        best = max(best, r - l + 1)
    return best

assert max_frequency([1,2,4], 5) == 3 and max_frequency([1,4,8,13], 5) == 2
