# LC#209 — Minimum Size Subarray Sum
# Difficulty: Medium | Pattern: Variable Sliding Window | Time: O(n) | Space: O(1)
def min_subarray_len(t, a):
    l = s = 0; best = float("inf")
    for r, x in enumerate(a):
        s += x
        while s >= t:
            best = min(best, r - l + 1); s -= a[l]; l += 1
    return 0 if best == float("inf") else best

assert min_subarray_len(7, [2,3,1,2,4,3]) == 2
