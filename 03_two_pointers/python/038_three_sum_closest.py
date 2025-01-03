# LC#16 — 3Sum Closest
# Difficulty: Medium | Pattern: Sort + Two Pointers | Time: O(n^2) | Space: O(1)
def three_sum_closest(a, t):
    a.sort(); best = a[0] + a[1] + a[2]
    for i in range(len(a) - 2):
        l, r = i + 1, len(a) - 1
        while l < r:
            s = a[i] + a[l] + a[r]
            if abs(s - t) < abs(best - t): best = s
            if s == t: return t
            if s < t: l += 1
            else: r -= 1
    return best

assert three_sum_closest([-1,2,1,-4], 1) == 2
