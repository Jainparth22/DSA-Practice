# LC#189 — Rotate Array
# Difficulty: Medium | Pattern: Reversal | Time: O(n) | Space: O(1)
def rotate(a, k):
    k %= len(a)
    a.reverse(); a[:k] = reversed(a[:k]); a[k:] = reversed(a[k:])

a = [1,2,3,4,5,6,7]; rotate(a, 3); assert a == [5,6,7,1,2,3,4]
