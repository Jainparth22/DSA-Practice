# LC#74 — Search a 2D Matrix
# Difficulty: Medium | Pattern: Binary Search on flattened matrix | Time: O(log mn) | Space: O(1)
def search_matrix(m, t):
    R, C = len(m), len(m[0]); l, r = 0, R * C - 1
    while l <= r:
        mid = (l + r) // 2; v = m[mid // C][mid % C]
        if v == t: return True
        if v < t: l = mid + 1
        else: r = mid - 1
    return False

m = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
assert search_matrix(m, 3) and not search_matrix(m, 13)
