// LC#62 — Unique Paths
// Difficulty: Medium | Pattern: 1D DP | Time: O(mn) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n) { vector<int> dp(n, 1); for (int i = 1; i < m; i++) for (int j = 1; j < n; j++) dp[j] += dp[j-1]; return dp[n-1]; }
int main() { cout << uniquePaths(3, 7) << endl; } // 28
