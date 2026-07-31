# LC#727 — Minimum Window Subsequence
# Difficulty: Hard | Pattern: Two pointers (forward/backward) | Time: O(mn) | Space: O(1)
def min_window(s, t):
    n, m, best, bs, i = len(s), len(t), float("inf"), 0, 0
    while i < n:
        j = 0
        while i < n:
            if s[i] == t[j]:
                j += 1
                if j == m: break
            i += 1
        if i == n: break
        end = i; j = m - 1
        while j >= 0:
            if s[i] == t[j]: j -= 1
            i -= 1
        i += 1
        if end - i + 1 < best: best, bs = end - i + 1, i
        i += 1
    return "" if best == float("inf") else s[bs:bs + best]

assert min_window("abcdebdde", "bde") == "bcde" and min_window("jmeqksfrsdcmsiwvaovztaqenprpvnbstl", "u") == ""
