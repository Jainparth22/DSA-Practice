// LC#1799 — Maximize Score After N Operations
// Difficulty: Hard | Pattern: Bitmask DP | Time: O(2^n * n^2) | Space: O(2^n)
#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int>& a) {
    int n = a.size(); vector<int> dp(1 << n);
    for (int m = 0; m < (1 << n); m++) { int k = __builtin_popcount(m); if (k % 2) continue; int op = k / 2 + 1;
        for (int i = 0; i < n; i++) if (!(m >> i & 1)) for (int j = i + 1; j < n; j++) if (!(m >> j & 1)) { int nm = m | 1 << i | 1 << j; dp[nm] = max(dp[nm], dp[m] + op * __gcd(a[i], a[j])); } }
    return dp[(1 << n) - 1];
}
int main() { vector<int> a = {3,4,6,8}; cout << maxScore(a) << endl; } // 11
