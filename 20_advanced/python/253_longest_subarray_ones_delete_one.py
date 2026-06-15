# LC#1493 — Longest Subarray of 1s After Deleting One Element
# Difficulty: Medium | Pattern: Sliding Window | Time: O(n) | Space: O(1)
def longest_subarray(a):
    l = zeros = best = 0
    for r, x in enumerate(a):
        zeros += x == 0
        while zeros > 1: zeros -= a[l] == 0; l += 1
        best = max(best, r - l)
    return best

assert longest_subarray([1,1,0,1]) == 3 and longest_subarray([1,1,1]) == 2
