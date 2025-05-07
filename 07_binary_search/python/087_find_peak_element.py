# LC#162 — Find Peak Element
# Difficulty: Medium | Pattern: Binary Search on slope | Time: O(log n) | Space: O(1)
def find_peak_element(a):
    l, r = 0, len(a) - 1
    while l < r:
        m = (l + r) // 2
        if a[m] < a[m + 1]: l = m + 1
        else: r = m
    return l

assert find_peak_element([1,2,1,3,5,6,4]) in (1, 5)
