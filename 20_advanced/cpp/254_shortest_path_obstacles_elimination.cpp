// LC#1293 — Shortest Path in a Grid with Obstacles Elimination
// Difficulty: Hard | Pattern: BFS with state (r, c, k) | Time: O(mnk) | Space: O(mnk)
#include <bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>>& g, int k) {
    int R = g.size(), C = g[0].size(); if (k >= R + C - 2) return R + C - 2;
    vector<vector<vector<bool>>> seen(R, vector<vector<bool>>(C, vector<bool>(k + 1)));
    queue<array<int,4>> q; q.push({0, 0, k, 0}); seen[0][0][k] = true; int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()) {
        auto [i, j, r, st] = q.front(); q.pop();
        if (i == R - 1 && j == C - 1) return st;
        for (auto& x : d) { int a = i + x[0], b = j + x[1]; if (a < 0 || b < 0 || a >= R || b >= C) continue; int nr = r - g[a][b]; if (nr >= 0 && !seen[a][b][nr]) { seen[a][b][nr] = true; q.push({a, b, nr, st + 1}); } }
    }
    return -1;
}
int main() { vector<vector<int>> g = {{0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}}; cout << shortestPath(g, 1) << endl; } // 6
