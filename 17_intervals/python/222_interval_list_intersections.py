# LC#986 — Interval List Intersections
# Difficulty: Medium | Pattern: Two Pointers | Time: O(m+n) | Space: O(m+n)
def interval_intersection(a, b):
    i = j = 0; r = []
    while i < len(a) and j < len(b):
        lo, hi = max(a[i][0], b[j][0]), min(a[i][1], b[j][1])
        if lo <= hi: r.append([lo, hi])
        if a[i][1] < b[j][1]: i += 1
        else: j += 1
    return r

assert interval_intersection([[0,2],[5,10]], [[1,5],[8,12]]) == [[1,2],[5,5],[8,10]]
