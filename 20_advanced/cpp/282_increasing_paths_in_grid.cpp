// LC#2328 — Number of Increasing Paths in a Grid
// Difficulty: Hard | Pattern: Memoized DFS | Time: O(mn) | Space: O(mn)
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int dfs(vector<vector<int>>& g, vector<vector<int>>& memo, int i, int j) {
    if (memo[i][j]) return memo[i][j]; long long res = 1; int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (auto& x : d) { int a = i + x[0], b = j + x[1]; if (a >= 0 && b >= 0 && a < (int)g.size() && b < (int)g[0].size() && g[a][b] > g[i][j]) res += dfs(g, memo, a, b); }
    return memo[i][j] = res % M;
}
int countPaths(vector<vector<int>>& g) { vector<vector<int>> memo(g.size(), vector<int>(g[0].size())); long long s = 0; for (int i = 0; i < (int)g.size(); i++) for (int j = 0; j < (int)g[0].size(); j++) s += dfs(g, memo, i, j); return s % M; }
int main() { vector<vector<int>> g = {{1,1},{3,4}}; cout << countPaths(g) << endl; } // 8
