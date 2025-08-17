// LC#1143 — Longest Common Subsequence
// Difficulty: Medium
// Pattern: 2D Dynamic Programming
// Time: O(m*n) | Space: O(m*n)
//
// Approach:
//   dp[i][j] = LCS of text1[0..i-1] and text2[0..j-1].
//   If chars match: dp[i][j] = dp[i-1][j-1] + 1.
//   Else:           dp[i][j] = max(dp[i-1][j], dp[i][j-1]).
//   Answer: dp[m][n].

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    cout << sol.longestCommonSubsequence("abcde", "ace")   << endl; // 3
    cout << sol.longestCommonSubsequence("abc", "abc")     << endl; // 3
    cout << sol.longestCommonSubsequence("abc", "def")     << endl; // 0
    cout << sol.longestCommonSubsequence("bl", "yby")      << endl; // 1
    cout << "All tests passed!" << endl;
    return 0;
}
