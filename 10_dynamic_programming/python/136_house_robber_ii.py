# LC#213 — House Robber II
# Difficulty: Medium | Pattern: DP (circular) | Time: O(n) | Space: O(1)
def rob(a):
    def rob1(arr):
        p = c = 0
        for x in arr: p, c = c, max(c, p + x)
        return c
    return a[0] if len(a) == 1 else max(rob1(a[:-1]), rob1(a[1:]))

assert rob([2,3,2]) == 3 and rob([1,2,3,1]) == 4
