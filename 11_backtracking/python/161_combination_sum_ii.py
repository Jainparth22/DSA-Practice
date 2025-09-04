# LC#40 — Combination Sum II
# Difficulty: Medium | Pattern: Backtracking + skip duplicates | Time: O(2^n) | Space: O(n)
def combination_sum2(a, t):
    a.sort(); res = []
    def go(i, rem, cur):
        if rem == 0: res.append(cur[:]); return
        for j in range(i, len(a)):
            if a[j] > rem: break
            if j > i and a[j] == a[j-1]: continue
            cur.append(a[j]); go(j + 1, rem - a[j], cur); cur.pop()
    go(0, t, [])
    return res

assert len(combination_sum2([10,1,2,7,6,1,5], 8)) == 4
