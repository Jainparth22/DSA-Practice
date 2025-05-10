# LC#4 — Median of Two Sorted Arrays
# Difficulty: Hard | Pattern: Binary Search on partition | Time: O(log min(m,n)) | Space: O(1)
def find_median_sorted_arrays(a, b):
    if len(a) > len(b): a, b = b, a
    m, n = len(a), len(b); l, r, half = 0, m, (m + n + 1) // 2
    while l <= r:
        i = (l + r) // 2; j = half - i
        aL = a[i-1] if i else float("-inf"); aR = a[i] if i < m else float("inf")
        bL = b[j-1] if j else float("-inf"); bR = b[j] if j < n else float("inf")
        if aL <= bR and bL <= aR:
            if (m + n) % 2: return max(aL, bL)
            return (max(aL, bL) + min(aR, bR)) / 2
        if aL > bR: r = i - 1
        else: l = i + 1

assert find_median_sorted_arrays([1,2], [3,4]) == 2.5 and find_median_sorted_arrays([1,3], [2]) == 2
