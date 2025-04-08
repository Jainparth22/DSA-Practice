# LC#287 — Find the Duplicate Number
# Difficulty: Medium | Pattern: Floyd Cycle Detection | Time: O(n) | Space: O(1)
def find_duplicate(a):
    s = f = a[0]
    while True:
        s = a[s]; f = a[a[f]]
        if s == f: break
    s = a[0]
    while s != f: s, f = a[s], a[f]
    return s

assert find_duplicate([1,3,4,2,2]) == 2 and find_duplicate([3,1,3,4,2]) == 3
