# LC#992 — Subarrays with K Different Integers
# Difficulty: Hard | Pattern: atMost(K) - atMost(K-1) | Time: O(n) | Space: O(k)
from collections import defaultdict

def at_most(a, k):
    cnt = defaultdict(int); l = res = 0
    for r, x in enumerate(a):
        cnt[x] += 1
        while len(cnt) > k:
            cnt[a[l]] -= 1
            if cnt[a[l]] == 0: del cnt[a[l]]
            l += 1
        res += r - l + 1
    return res

def subarrays_with_k_distinct(a, k):
    return at_most(a, k) - at_most(a, k - 1)

assert subarrays_with_k_distinct([1,2,1,2,3], 2) == 7
