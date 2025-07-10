// LC#323 — Number of Connected Components
// Difficulty: Medium | Pattern: Union Find | Time: O(E α(V)) | Space: O(V)
#include <bits/stdc++.h>
using namespace std;
int p[2000];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
int countComponents(int n, vector<vector<int>>& e) {
    iota(p, p + n, 0); int c = n;
    for (auto& x : e) { int a = find(x[0]), b = find(x[1]); if (a != b) { p[a] = b; c--; } }
    return c;
}
int main() { vector<vector<int>> e = {{0,1},{1,2},{3,4}}; cout << countComponents(5, e) << endl; } // 2
