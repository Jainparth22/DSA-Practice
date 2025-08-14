// LC#97 — Interleaving String
// Difficulty: Hard | Pattern: 2D DP | Time: O(mn) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
bool isInterleave(string a, string b, string c) {
    int m = a.size(), n = b.size(); if (m + n != (int)c.size()) return false;
    vector<bool> dp(n + 1);
    for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) {
        if (!i && !j) dp[j] = true;
        else dp[j] = (i && dp[j] && a[i-1] == c[i+j-1]) || (j && dp[j-1] && b[j-1] == c[i+j-1]);
    }
    return dp[n];
}
int main() { cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl; } // 10
