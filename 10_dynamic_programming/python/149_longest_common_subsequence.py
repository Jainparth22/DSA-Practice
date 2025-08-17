# LC#1143 — Longest Common Subsequence
# Difficulty: Medium
# Pattern: 2D Dynamic Programming
# Time: O(m*n) | Space: O(m*n)
#
# Approach:
#   dp[i][j] = LCS length of text1[:i] and text2[:j].
#   Match: dp[i][j] = dp[i-1][j-1] + 1
#   No match: dp[i][j] = max(dp[i-1][j], dp[i][j-1])

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[m][n]


if __name__ == "__main__":
    s = Solution()
    assert s.longestCommonSubsequence("abcde", "ace") == 3
    assert s.longestCommonSubsequence("abc", "abc") == 3
    assert s.longestCommonSubsequence("abc", "def") == 0
    assert s.longestCommonSubsequence("bl", "yby") == 1
    print("All tests passed!")
