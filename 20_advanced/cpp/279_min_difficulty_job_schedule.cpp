// LC#1335 — Minimum Difficulty of a Job Schedule
// Difficulty: Hard | Pattern: DP | Time: O(d * n^2) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int minDifficulty(vector<int>& j, int d) {
    int n = j.size(); if (n < d) return -1; const int INF = 1e9; vector<int> dp(n + 1, INF); dp[0] = 0;
    for (int day = 1; day <= d; day++) { vector<int> nd(n + 1, INF); for (int i = day; i <= n; i++) { int mx = 0; for (int k = i; k >= day; k--) { mx = max(mx, j[k-1]); if (dp[k-1] < INF) nd[i] = min(nd[i], dp[k-1] + mx); } } dp = nd; }
    return dp[n];
}
int main() { vector<int> a = {6,5,4,3,2,1}, b = {9,9,9}; cout << minDifficulty(a, 2) << minDifficulty(b, 4) << endl; } // 7-1
