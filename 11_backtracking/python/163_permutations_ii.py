# LC#47 — Permutations II
# Difficulty: Medium | Pattern: Backtracking + used[] | Time: O(n * n!) | Space: O(n)
def permute_unique(a):
    a.sort(); res = []; used = [False] * len(a)
    def go(cur):
        if len(cur) == len(a): res.append(cur[:]); return
        for i in range(len(a)):
            if used[i] or (i and a[i] == a[i-1] and not used[i-1]): continue
            used[i] = True; cur.append(a[i]); go(cur); cur.pop(); used[i] = False
    go([])
    return res

assert len(permute_unique([1,1,2])) == 3
