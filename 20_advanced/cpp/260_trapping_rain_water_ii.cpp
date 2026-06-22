// LC#407 — Trapping Rain Water II
// Difficulty: Hard | Pattern: Min Heap BFS from border | Time: O(mn log mn) | Space: O(mn)
#include <bits/stdc++.h>
using namespace std;
int trapRainWater(vector<vector<int>>& h) {
    int R = h.size(), C = h[0].size(), res = 0; if (R < 3 || C < 3) return 0;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq; vector<vector<bool>> seen(R, vector<bool>(C));
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (i == 0 || j == 0 || i == R - 1 || j == C - 1) { pq.push({h[i][j], i, j}); seen[i][j] = true; }
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (!pq.empty()) {
        auto [ht, i, j] = pq.top(); pq.pop();
        for (auto& x : d) { int a = i + x[0], b = j + x[1]; if (a < 0 || b < 0 || a >= R || b >= C || seen[a][b]) continue; seen[a][b] = true; res += max(0, ht - h[a][b]); pq.push({max(ht, h[a][b]), a, b}); }
    }
    return res;
}
int main() { vector<vector<int>> h = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}}; cout << trapRainWater(h) << endl; } // 4
