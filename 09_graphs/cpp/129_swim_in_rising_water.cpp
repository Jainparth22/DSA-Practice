// LC#778 — Swim in Rising Water
// Difficulty: Hard | Pattern: Dijkstra on max-cell | Time: O(n^2 log n) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
int swimInWater(vector<vector<int>>& g) {
    int n = g.size(); vector<vector<int>> seen(n, vector<int>(n));
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq; pq.push({g[0][0], 0, 0}); seen[0][0] = 1;
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!pq.empty()) {
        auto [t, i, j] = pq.top(); pq.pop();
        if (i == n - 1 && j == n - 1) return t;
        for (auto& k : d) { int x = i + k[0], y = j + k[1]; if (x >= 0 && y >= 0 && x < n && y < n && !seen[x][y]) { seen[x][y] = 1; pq.push({max(t, g[x][y]), x, y}); } }
    }
    return -1;
}
int main() { vector<vector<int>> g = {{0,2},{1,3}}; cout << swimInWater(g) << endl; } // 3
