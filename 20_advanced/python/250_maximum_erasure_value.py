# LC#1695 — Maximum Erasure Value
# Difficulty: Medium | Pattern: Sliding window + set | Time: O(n) | Space: O(n)
def maximum_unique_subarray(a):
    seen = set(); l = s = best = 0
    for x in a:
        while x in seen: seen.remove(a[l]); s -= a[l]; l += 1
        seen.add(x); s += x; best = max(best, s)
    return best

assert maximum_unique_subarray([4,2,4,5,6]) == 17
