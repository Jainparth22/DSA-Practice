# LC#647 — Palindromic Substrings
# Difficulty: Medium | Pattern: Expand Around Center | Time: O(n^2) | Space: O(1)
def count_substrings(s):
    n, cnt = len(s), 0
    for c in range(2 * n - 1):
        l = c // 2; r = l + c % 2
        while l >= 0 and r < n and s[l] == s[r]:
            cnt += 1; l -= 1; r += 1
    return cnt

assert count_substrings("aaa") == 6
