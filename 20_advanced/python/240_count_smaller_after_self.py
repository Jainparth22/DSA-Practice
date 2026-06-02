# LC#315 — Count of Smaller Numbers After Self
# Difficulty: Hard | Pattern: Fenwick Tree (BIT) | Time: O(n log n) | Space: O(n)
import bisect

def count_smaller(a):
    s = sorted(set(a)); m = len(s); bit = [0] * (m + 1); res = [0] * len(a)
    for i in range(len(a) - 1, -1, -1):
        r = bisect.bisect_left(s, a[i]); k = r
        while k > 0: res[i] += bit[k]; k -= k & -k
        k = r + 1
        while k <= m: bit[k] += 1; k += k & -k
    return res

assert count_smaller([5,2,6,1]) == [2,1,1,0]
