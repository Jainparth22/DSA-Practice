// LC#72 — Edit Distance (Levenshtein Distance)
// Difficulty: Hard
// Pattern: 2D DP
// Time: O(m*n) | Space: O(m*n)
//
// Approach:
//   dp[i][j] = min edits to convert word1[0..i-1] to word2[0..j-1].
//   Base cases: dp[i][0] = i (delete all), dp[0][j] = j (insert all).
//   If chars match: dp[i][j] = dp[i-1][j-1] (no new op needed).
//   If not:         dp[i][j] = 1 + min(dp[i-1][j],    // delete from word1
//                                      dp[i][j-1],    // insert into word1
//                                      dp[i-1][j-1])  // replace

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    cout << sol.minDistance("horse", "ros")     << endl; // 3
    cout << sol.minDistance("intention", "execution") << endl; // 5
    cout << sol.minDistance("", "a")            << endl; // 1
    cout << sol.minDistance("a", "")            << endl; // 1
    cout << sol.minDistance("abc", "abc")       << endl; // 0
    cout << "All tests passed!" << endl;
    return 0;
}
