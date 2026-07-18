// LC#1368 — Minimum Cost to Make at Least One Valid Path in a Grid
// Difficulty: Hard | Pattern: 0-1 BFS | Time: O(mn) | Space: O(mn)
#include <bits/stdc++.h>
using namespace std;
int minCost(vector<vector<int>>& g) {
    int R = g.size(), C = g[0].size(); vector<vector<int>> d(R, vector<int>(C, INT_MAX)); deque<pair<int,int>> q; d[0][0] = 0; q.push_back({0, 0});
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};  // arrows 1..4
    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop_front();
        for (int k = 0; k < 4; k++) { int a = i + dx[k], b = j + dy[k]; if (a < 0 || b < 0 || a >= R || b >= C) continue; int w = g[i][j] != k + 1;
            if (d[i][j] + w < d[a][b]) { d[a][b] = d[i][j] + w; w ? q.push_back({a, b}) : q.push_front({a, b}); } }
    }
    return d[R-1][C-1];
}
int main() { vector<vector<int>> g = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}}; cout << minCost(g) << endl; } // 3
