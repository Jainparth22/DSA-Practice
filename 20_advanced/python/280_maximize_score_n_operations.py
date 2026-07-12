# LC#1799 — Maximize Score After N Operations
# Difficulty: Hard | Pattern: Bitmask DP | Time: O(2^n * n^2) | Space: O(2^n)
from math import gcd

def max_score(a):
    n = len(a); dp = [0] * (1 << n)
    for m in range(1 << n):
        k = bin(m).count("1")
        if k % 2: continue
        op = k // 2 + 1
        for i in range(n):
            if m >> i & 1: continue
            for j in range(i + 1, n):
                if m >> j & 1: continue
                nm = m | 1 << i | 1 << j; dp[nm] = max(dp[nm], dp[m] + op * gcd(a[i], a[j]))
    return dp[-1]

assert max_score([1,2]) == 1 and max_score([3,4,6,8]) == 11 and max_score([1,2,3,4,5,6]) == 14
