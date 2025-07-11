// LC#261 — Graph Valid Tree
// Difficulty: Medium | Pattern: Union Find (n-1 edges, no cycle) | Time: O(E α(V)) | Space: O(V)
#include <bits/stdc++.h>
using namespace std;
int p[2000];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
bool validTree(int n, vector<vector<int>>& e) {
    if ((int)e.size() != n - 1) return false;
    iota(p, p + n, 0);
    for (auto& x : e) { int a = find(x[0]), b = find(x[1]); if (a == b) return false; p[a] = b; }
    return true;
}
int main() { vector<vector<int>> e = {{0,1},{0,2},{0,3},{1,4}}, f = {{0,1},{1,2},{2,3},{1,3},{1,4}}; cout << validTree(5, e) << validTree(5, f) << endl; } // 10
