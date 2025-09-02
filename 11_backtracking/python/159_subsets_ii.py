# LC#90 — Subsets II
# Difficulty: Medium | Pattern: Backtracking + skip duplicates | Time: O(n * 2^n) | Space: O(n)
def subsets_with_dup(a):
    a.sort(); res = []
    def go(i, cur):
        res.append(cur[:])
        for j in range(i, len(a)):
            if j > i and a[j] == a[j-1]: continue
            cur.append(a[j]); go(j + 1, cur); cur.pop()
    go(0, [])
    return res

assert len(subsets_with_dup([1,2,2])) == 6
