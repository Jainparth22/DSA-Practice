// LC#664 — Strange Printer
// Difficulty: Hard | Pattern: Interval DP | Time: O(n^3) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
int strangePrinter(string s) {
    int n = s.size(); vector<vector<int>> dp(n, vector<int>(n));
    for (int l = n - 1; l >= 0; l--) { dp[l][l] = 1; for (int r = l + 1; r < n; r++) { dp[l][r] = dp[l][r-1] + 1; for (int k = l; k < r; k++) if (s[k] == s[r]) dp[l][r] = min(dp[l][r], dp[l][k] + (k + 1 <= r - 1 ? dp[k+1][r-1] : 0)); } }
    return n ? dp[0][n-1] : 0;
}
int main() { cout << strangePrinter("aaabbb") << strangePrinter("aba") << endl; } // 22
