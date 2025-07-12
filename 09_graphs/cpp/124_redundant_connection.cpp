// LC#684 — Redundant Connection
// Difficulty: Medium | Pattern: Union Find | Time: O(n α(n)) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int p[1001];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
vector<int> findRedundantConnection(vector<vector<int>>& e) {
    iota(p, p + 1001, 0);
    for (auto& x : e) { int a = find(x[0]), b = find(x[1]); if (a == b) return x; p[a] = b; }
    return {};
}
int main() { vector<vector<int>> e = {{1,2},{1,3},{2,3}}; auto r = findRedundantConnection(e); cout << r[0] << r[1] << endl; } // 23
