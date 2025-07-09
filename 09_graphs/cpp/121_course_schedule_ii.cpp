// LC#210 — Course Schedule II
// Difficulty: Medium | Pattern: Topological Sort (Kahn) | Time: O(V+E) | Space: O(V+E)
#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int n, vector<vector<int>>& pre) {
    vector<vector<int>> g(n); vector<int> indeg(n), order; queue<int> q;
    for (auto& p : pre) { g[p[1]].push_back(p[0]); indeg[p[0]]++; }
    for (int i = 0; i < n; i++) if (!indeg[i]) q.push(i);
    while (!q.empty()) { int u = q.front(); q.pop(); order.push_back(u); for (int v : g[u]) if (!--indeg[v]) q.push(v); }
    return (int)order.size() == n ? order : vector<int>{};
}
int main() { vector<vector<int>> p = {{1,0},{2,0},{3,1},{3,2}}; auto o = findOrder(4, p); cout << o.size() << o[0] << endl; } // 40
