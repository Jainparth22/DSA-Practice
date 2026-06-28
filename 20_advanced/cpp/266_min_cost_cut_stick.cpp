// LC#1547 — Minimum Cost to Cut a Stick
// Difficulty: Hard | Pattern: Interval DP | Time: O(n^3) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
int minCost(int n, vector<int>& cuts) {
    vector<int> c = {0}; c.insert(c.end(), cuts.begin(), cuts.end()); c.push_back(n); sort(c.begin(), c.end()); int m = c.size();
    vector<vector<int>> dp(m, vector<int>(m));
    for (int len = 2; len < m; len++) for (int i = 0; i + len < m; i++) { int j = i + len; dp[i][j] = INT_MAX; for (int k = i + 1; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + c[j] - c[i]); }
    return dp[0][m-1];
}
int main() { vector<int> c = {1,3,4,5}; cout << minCost(7, c) << endl; } // 16
