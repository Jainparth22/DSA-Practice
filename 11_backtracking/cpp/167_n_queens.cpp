// LC#51 — N-Queens
// Difficulty: Hard | Pattern: Backtracking + column/diagonal sets | Time: O(n!) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
void go(int r, int n, vector<int>& cols, vector<bool>& c, vector<bool>& d1, vector<bool>& d2, vector<vector<string>>& res) {
    if (r == n) { vector<string> b(n, string(n, '.')); for (int i = 0; i < n; i++) b[i][cols[i]] = 'Q'; res.push_back(b); return; }
    for (int j = 0; j < n; j++) {
        if (c[j] || d1[r + j] || d2[r - j + n]) continue;
        c[j] = d1[r + j] = d2[r - j + n] = true; cols[r] = j;
        go(r + 1, n, cols, c, d1, d2, res);
        c[j] = d1[r + j] = d2[r - j + n] = false;
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res; vector<int> cols(n); vector<bool> c(n), d1(2 * n), d2(2 * n + 1);
    go(0, n, cols, c, d1, d2, res); return res;
}
int main() { cout << solveNQueens(4).size() << solveNQueens(8).size() << endl; } // 292
