# LC#977 — Squares of a Sorted Array
# Difficulty: Easy | Pattern: Two Pointers | Time: O(n) | Space: O(n)
def sorted_squares(a):
    n, l, r = len(a), 0, len(a) - 1; res = [0] * n
    for k in range(n - 1, -1, -1):
        if abs(a[l]) > abs(a[r]):
            res[k] = a[l] ** 2; l += 1
        else:
            res[k] = a[r] ** 2; r -= 1
    return res

assert sorted_squares([-4,-1,0,3,10]) == [0,1,9,16,100]
