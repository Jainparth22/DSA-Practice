// LC#312 — Burst Balloons
// Difficulty: Hard | Pattern: Interval DP | Time: O(n^3) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
int maxCoins(vector<int>& nums) {
    vector<int> a = {1}; a.insert(a.end(), nums.begin(), nums.end()); a.push_back(1); int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int len = 2; len < n; len++) for (int l = 0; l + len < n; l++) { int r = l + len; for (int k = l + 1; k < r; k++) dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + a[l] * a[k] * a[r]); }
    return dp[0][n-1];
}
int main() { vector<int> a = {3,1,5,8}; cout << maxCoins(a) << endl; } // 167
