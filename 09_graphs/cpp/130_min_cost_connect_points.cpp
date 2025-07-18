// LC#1584 — Min Cost to Connect All Points
// Difficulty: Medium | Pattern: Prim's MST | Time: O(n^2) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int minCostConnectPoints(vector<vector<int>>& p) {
    int n = p.size(), total = 0; vector<int> d(n, INT_MAX); vector<bool> in(n);
    d[0] = 0;
    for (int it = 0; it < n; it++) {
        int u = -1;
        for (int i = 0; i < n; i++) if (!in[i] && (u < 0 || d[i] < d[u])) u = i;
        in[u] = true; total += d[u];
        for (int v = 0; v < n; v++) if (!in[v]) d[v] = min(d[v], abs(p[u][0] - p[v][0]) + abs(p[u][1] - p[v][1]));
    }
    return total;
}
int main() { vector<vector<int>> p = {{0,0},{2,2},{3,10},{5,2},{7,0}}; cout << minCostConnectPoints(p) << endl; } // 20
