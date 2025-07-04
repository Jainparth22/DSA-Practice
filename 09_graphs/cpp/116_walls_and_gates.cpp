// LC#286 — Walls and Gates
// Difficulty: Medium | Pattern: Multi-source BFS | Time: O(mn) | Space: O(mn)
#include <bits/stdc++.h>
using namespace std;
void wallsAndGates(vector<vector<int>>& g) {
    int R = g.size(), C = g[0].size(); queue<pair<int,int>> q;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (!g[i][j]) q.push({i, j});
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (auto& k : d) { int x = i + k[0], y = j + k[1]; if (x >= 0 && y >= 0 && x < R && y < C && g[x][y] == INT_MAX) { g[x][y] = g[i][j] + 1; q.push({x, y}); } }
    }
}
int main() { int I = INT_MAX; vector<vector<int>> g = {{I,-1,0,I},{I,I,I,-1},{I,-1,I,-1},{0,-1,I,I}}; wallsAndGates(g); cout << g[0][0] << endl; } // 3
