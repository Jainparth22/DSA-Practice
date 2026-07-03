# LC#410 — Split Array Largest Sum
# Difficulty: Hard | Pattern: Binary Search on answer | Time: O(n log S) | Space: O(1)
def split_array(a, k):
    lo, hi = max(a), sum(a)
    while lo < hi:
        m = (lo + hi) // 2; cnt, cur = 1, 0
        for x in a:
            if cur + x > m: cnt += 1; cur = 0
            cur += x
        if cnt <= k: hi = m
        else: lo = m + 1
    return lo

assert split_array([7,2,5,10,8], 2) == 18 and split_array([1,2,3,4,5], 2) == 9
