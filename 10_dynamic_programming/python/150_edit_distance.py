# LC#72 — Edit Distance
# Difficulty: Hard
# Pattern: 2D Dynamic Programming
# Time: O(m*n) | Space: O(m*n)
#
# Approach:
#   dp[i][j] = min edits to convert word1[:i] → word2[:j].
#   Match: dp[i][j] = dp[i-1][j-1]
#   No match: dp[i][j] = 1 + min(delete, insert, replace)

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            dp[i][0] = i
        for j in range(n + 1):
            dp[0][j] = j
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = 1 + min(dp[i - 1][j],      # delete
                                       dp[i][j - 1],      # insert
                                       dp[i - 1][j - 1])  # replace
        return dp[m][n]


if __name__ == "__main__":
    s = Solution()
    assert s.minDistance("horse", "ros") == 3
    assert s.minDistance("intention", "execution") == 5
    assert s.minDistance("", "a") == 1
    assert s.minDistance("abc", "abc") == 0
    print("All tests passed!")
