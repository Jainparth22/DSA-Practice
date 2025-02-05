# LC#76 — Minimum Window Substring
# Difficulty: Hard | Pattern: Sliding Window | Time: O(n) | Space: O(k)
from collections import Counter

def min_window(s, t):
    need, missing = Counter(t), len(t)
    best, l = (float("inf"), 0), 0
    for r, c in enumerate(s):
        if need[c] > 0: missing -= 1
        need[c] -= 1
        while missing == 0:
            if r - l + 1 < best[0]: best = (r - l + 1, l)
            need[s[l]] += 1
            if need[s[l]] > 0: missing += 1
            l += 1
    return "" if best[0] == float("inf") else s[best[1]:best[1] + best[0]]

assert min_window("ADOBECODEBANC", "ABC") == "BANC"
