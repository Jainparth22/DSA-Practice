# LC#278 — First Bad Version
# Difficulty: Easy | Pattern: Binary Search | Time: O(log n) | Space: O(1)
BAD = 4
def is_bad_version(v): return v >= BAD

def first_bad_version(n):
    l, r = 1, n
    while l < r:
        m = (l + r) // 2
        if is_bad_version(m): r = m
        else: l = m + 1
    return l

assert first_bad_version(5) == 4
