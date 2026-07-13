// LC#1931 — Painting a Grid With Three Different Colors
// Difficulty: Hard | Pattern: Column-pattern DP | Time: O(n * P^2) | Space: O(P^2)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cols;
void gen(int m, vector<int>& cur) { if ((int)cur.size() == m) { cols.push_back(cur); return; } for (int c = 0; c < 3; c++) if (cur.empty() || cur.back() != c) { cur.push_back(c); gen(m, cur); cur.pop_back(); } }
int colorTheGrid(int m, int n) {
    const int M = 1e9 + 7; cols.clear(); vector<int> cur; gen(m, cur); int p = cols.size();
    vector<vector<int>> ok(p); for (int i = 0; i < p; i++) for (int j = 0; j < p; j++) { bool f = true; for (int r = 0; r < m; r++) if (cols[i][r] == cols[j][r]) f = false; if (f) ok[i].push_back(j); }
    vector<long long> dp(p, 1);
    for (int k = 1; k < n; k++) { vector<long long> nd(p); for (int i = 0; i < p; i++) for (int j : ok[i]) nd[i] = (nd[i] + dp[j]) % M; dp = nd; }
    long long s = 0; for (long long v : dp) s = (s + v) % M; return s;
}
int main() { cout << colorTheGrid(1, 1) << " " << colorTheGrid(5, 5) << endl; } // 3 580986
