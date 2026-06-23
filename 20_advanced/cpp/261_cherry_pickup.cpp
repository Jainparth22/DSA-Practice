// LC#741 — Cherry Pickup
// Difficulty: Hard | Pattern: DP on two simultaneous paths | Time: O(n^3) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
int cherryPickup(vector<vector<int>>& g) {
    int n = g.size(), NEG = -1e9; vector<vector<int>> dp(n, vector<int>(n, NEG)); dp[0][0] = g[0][0];
    for (int k = 1; k <= 2 * n - 2; k++) {
        vector<vector<int>> nd(n, vector<int>(n, NEG));
        for (int i = max(0, k - n + 1); i <= min(n - 1, k); i++) for (int j = i; j <= min(n - 1, k); j++) {
            int a = k - i, b = k - j; if (g[i][a] < 0 || g[j][b] < 0) continue;
            int best = NEG; for (int pi : {i, i - 1}) for (int pj : {j, j - 1}) if (pi >= 0 && pj >= 0) best = max(best, dp[pi][pj]);
            if (best == NEG) continue;
            nd[i][j] = best + g[i][a] + (i != j ? g[j][b] : 0);
        }
        dp = nd;
    }
    return max(0, dp[n-1][n-1]);
}
int main() { vector<vector<int>> g = {{0,1,-1},{1,0,-1},{1,1,1}}; cout << cherryPickup(g) << endl; } // 5
