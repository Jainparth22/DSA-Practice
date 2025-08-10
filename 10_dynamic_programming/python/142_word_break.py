# LC#139 — Word Break
# Difficulty: Medium | Pattern: 1D DP | Time: O(n^2) | Space: O(n)
def word_break(s, words):
    d = set(words); dp = [True] + [False] * len(s)
    for i in range(1, len(s) + 1):
        dp[i] = any(dp[j] and s[j:i] in d for j in range(i))
    return dp[-1]

assert word_break("leetcode", ["leet","code"]) and not word_break("catsandog", ["cats","dog","sand","and","cat"])
