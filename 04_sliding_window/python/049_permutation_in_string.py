# LC#567 — Permutation in String
# Difficulty: Medium | Pattern: Fixed Sliding Window | Time: O(n) | Space: O(1)
def check_inclusion(p, s):
    m = len(p)
    if m > len(s): return False
    a = [0] * 26; b = [0] * 26
    for i in range(m):
        a[ord(p[i]) - 97] += 1; b[ord(s[i]) - 97] += 1
    if a == b: return True
    for i in range(m, len(s)):
        b[ord(s[i]) - 97] += 1; b[ord(s[i - m]) - 97] -= 1
        if a == b: return True
    return False

assert check_inclusion("ab", "eidbaooo") and not check_inclusion("ab", "eidboaoo")
