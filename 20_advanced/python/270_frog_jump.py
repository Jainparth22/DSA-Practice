# LC#403 — Frog Jump
# Difficulty: Hard | Pattern: DP with sets of jump sizes | Time: O(n^2) | Space: O(n^2)
def can_cross(stones):
    m = {x: set() for x in stones}; m[0].add(0)
    for x in stones:
        for k in m[x]:
            for d in (k - 1, k, k + 1):
                if d > 0 and x + d in m: m[x + d].add(d)
    return bool(m[stones[-1]])

assert can_cross([0,1,3,5,6,8,12,17]) and not can_cross([0,1,2,3,4,8,9,11])
