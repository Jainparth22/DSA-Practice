# LC#88 — Merge Sorted Array
# Difficulty: Easy | Pattern: Two Pointers (from end) | Time: O(m+n) | Space: O(1)
def merge(a, m, b, n):
    i, j, k = m - 1, n - 1, m + n - 1
    while j >= 0:
        if i >= 0 and a[i] > b[j]:
            a[k] = a[i]; i -= 1
        else:
            a[k] = b[j]; j -= 1
        k -= 1

a = [1,2,3,0,0,0]; merge(a, 3, [2,5,6], 3); assert a == [1,2,2,3,5,6]
