# LC#18 — 4Sum
# Difficulty: Medium | Pattern: Sort + Two Pointers | Time: O(n^3) | Space: O(1)
def four_sum(a, t):
    a.sort(); n = len(a); res = []
    for i in range(n - 3):
        if i and a[i] == a[i-1]: continue
        for j in range(i + 1, n - 2):
            if j > i + 1 and a[j] == a[j-1]: continue
            l, r = j + 1, n - 1
            while l < r:
                s = a[i] + a[j] + a[l] + a[r]
                if s == t:
                    res.append([a[i], a[j], a[l], a[r]]); l += 1; r -= 1
                    while l < r and a[l] == a[l-1]: l += 1
                elif s < t: l += 1
                else: r -= 1
    return res

assert len(four_sum([1,0,-1,0,-2,2], 0)) == 3
