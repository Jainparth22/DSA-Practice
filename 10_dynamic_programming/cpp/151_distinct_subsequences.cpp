// LC#115 — Distinct Subsequences
// Difficulty: Hard | Pattern: 1D DP | Time: O(mn) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int numDistinct(string s, string t) {
    int m = s.size(), n = t.size(); vector<unsigned long long> dp(n + 1); dp[0] = 1;
    for (int i = 0; i < m; i++) for (int j = n; j >= 1; j--) if (s[i] == t[j-1]) dp[j] += dp[j-1];
    return dp[n];
}
int main() { cout << numDistinct("rabbbit", "rabbit") << endl; } // 3
