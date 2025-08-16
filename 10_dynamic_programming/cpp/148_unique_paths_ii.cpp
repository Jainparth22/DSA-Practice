// LC#63 — Unique Paths II
// Difficulty: Medium | Pattern: 1D DP with obstacles | Time: O(mn) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& g) {
    int n = g[0].size(); vector<long long> dp(n); dp[0] = 1;
    for (auto& row : g) for (int j = 0; j < n; j++) { if (row[j]) dp[j] = 0; else if (j) dp[j] += dp[j-1]; }
    return dp[n-1];
}
int main() { vector<vector<int>> g = {{0,0,0},{0,1,0},{0,0,0}}; cout << uniquePathsWithObstacles(g) << endl; } // 2
