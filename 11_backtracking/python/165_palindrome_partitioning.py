# LC#131 — Palindrome Partitioning
# Difficulty: Medium | Pattern: Backtracking | Time: O(n * 2^n) | Space: O(n)
def partition(s):
    res = []
    def go(i, cur):
        if i == len(s): res.append(cur[:]); return
        for j in range(i, len(s)):
            sub = s[i:j+1]
            if sub == sub[::-1]: cur.append(sub); go(j + 1, cur); cur.pop()
    go(0, [])
    return res

assert partition("aab") == [["a","a","b"],["aa","b"]]
