# LC#438 — Find All Anagrams in a String
# Difficulty: Medium | Pattern: Fixed Sliding Window | Time: O(n) | Space: O(1)
def find_anagrams(s, p):
    m, n = len(p), len(s); res = []
    if m > n: return res
    a = [0] * 26; b = [0] * 26
    for i in range(m):
        a[ord(p[i]) - 97] += 1; b[ord(s[i]) - 97] += 1
    if a == b: res.append(0)
    for i in range(m, n):
        b[ord(s[i]) - 97] += 1; b[ord(s[i - m]) - 97] -= 1
        if a == b: res.append(i - m + 1)
    return res

assert find_anagrams("cbaebabacd", "abc") == [0, 6]
