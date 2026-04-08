// LC#221 — Maximal Square
// Difficulty: Medium | Pattern: 2D DP | Time: O(mn) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int maximalSquare(vector<vector<char>>& m) {
    int R = m.size(), C = m[0].size(), best = 0; vector<int> dp(C + 1);
    for (int i = 1; i <= R; i++) { int prev = 0; for (int j = 1; j <= C; j++) {
        int tmp = dp[j]; dp[j] = m[i-1][j-1] == '1' ? 1 + min({dp[j], dp[j-1], prev}) : 0; best = max(best, dp[j]); prev = tmp; } }
    return best * best;
}
int main() { vector<vector<char>> m = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}}; cout << maximalSquare(m) << endl; } // 4
