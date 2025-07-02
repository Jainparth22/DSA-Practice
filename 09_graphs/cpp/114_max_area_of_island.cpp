// LC#695 — Max Area of Island
// Difficulty: Medium | Pattern: DFS on grid | Time: O(mn) | Space: O(mn)
#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<int>>& g, int i, int j) {
    if (i < 0 || j < 0 || i >= (int)g.size() || j >= (int)g[0].size() || !g[i][j]) return 0;
    g[i][j] = 0;
    return 1 + dfs(g, i+1, j) + dfs(g, i-1, j) + dfs(g, i, j+1) + dfs(g, i, j-1);
}
int maxAreaOfIsland(vector<vector<int>>& g) {
    int best = 0;
    for (int i = 0; i < (int)g.size(); i++) for (int j = 0; j < (int)g[0].size(); j++) best = max(best, dfs(g, i, j));
    return best;
}
int main() { vector<vector<int>> g = {{1,1,0},{0,1,0},{0,0,1}}; cout << maxAreaOfIsland(g) << endl; } // 3
