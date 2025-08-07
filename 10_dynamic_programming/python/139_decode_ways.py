# LC#91 — Decode Ways
# Difficulty: Medium | Pattern: 1D DP | Time: O(n) | Space: O(1)
def num_decodings(s):
    a, b = 1, int(s[0] != "0")
    for i in range(2, len(s) + 1):
        c = 0
        if s[i-1] != "0": c += b
        if 10 <= int(s[i-2:i]) <= 26: c += a
        a, b = b, c
    return b

assert num_decodings("226") == 3 and num_decodings("06") == 0 and num_decodings("12") == 2
