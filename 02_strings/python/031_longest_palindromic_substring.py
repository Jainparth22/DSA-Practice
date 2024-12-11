# LC#5 — Longest Palindromic Substring
# Difficulty: Medium | Pattern: Expand Around Center | Time: O(n^2) | Space: O(1)
def longest_palindrome(s):
    n, bs, bl = len(s), 0, 0
    for c in range(2 * n - 1):
        l = c // 2; r = l + c % 2
        while l >= 0 and r < n and s[l] == s[r]:
            l -= 1; r += 1
        if r - l - 1 > bl: bl, bs = r - l - 1, l + 1
    return s[bs:bs + bl]

assert longest_palindrome("babad") in ("bab", "aba") and longest_palindrome("cbbd") == "bb"
