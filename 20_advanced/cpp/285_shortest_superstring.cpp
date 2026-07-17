// LC#943 — Find the Shortest Superstring
// Difficulty: Hard | Pattern: Bitmask DP (TSP) | Time: O(2^n * n^2) | Space: O(2^n * n)
#include <bits/stdc++.h>
using namespace std;
string shortestSuperstring(vector<string>& w) {
    int n = w.size(); vector<vector<int>> ov(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) for (int k = min(w[i].size(), w[j].size()); k > 0; k--) if (w[i].compare(w[i].size() - k, k, w[j], 0, k) == 0) { ov[i][j] = k; break; }
    const int INF = 1e9; vector<vector<int>> dp(1 << n, vector<int>(n, INF)), par(1 << n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) dp[1 << i][i] = w[i].size();
    for (int m = 0; m < (1 << n); m++) for (int i = 0; i < n; i++) if (dp[m][i] < INF) for (int j = 0; j < n; j++) if (!(m >> j & 1)) {
        int nm = m | 1 << j, c = dp[m][i] + w[j].size() - ov[i][j]; if (c < dp[nm][j]) { dp[nm][j] = c; par[nm][j] = i; } }
    int full = (1 << n) - 1, last = min_element(dp[full].begin(), dp[full].end()) - dp[full].begin(); vector<int> order;
    for (int m = full, i = last; i != -1;) { order.push_back(i); int p = par[m][i]; m ^= 1 << i; i = p; }
    reverse(order.begin(), order.end()); string res = w[order[0]];
    for (size_t k = 1; k < order.size(); k++) res += w[order[k]].substr(ov[order[k-1]][order[k]]);
    return res;
}
int main() { vector<string> w = {"alex","loves","leetcode"}; cout << shortestSuperstring(w).size() << endl; } // 17
