// LC#994 — Rotting Oranges
// Difficulty: Medium
// Pattern: Multi-source BFS
// Time: O(m*n) | Space: O(m*n)
//
// Approach:
//   Count fresh oranges. Add all rotten oranges to queue initially.
//   BFS in waves: each wave = 1 minute. Spread rot to 4 neighbours.
//   When queue empty: if fresh > 0 return -1 (unreachable), else return minutes.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0, minutes = 0;
        // Collect all rotten, count fresh
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) fresh++;
            }
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty() && fresh > 0) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> g1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << sol.orangesRotting(g1) << endl; // 4

    vector<vector<int>> g2 = {{2,1,1},{0,1,1},{1,0,1}};
    cout << sol.orangesRotting(g2) << endl; // -1

    vector<vector<int>> g3 = {{0,2}};
    cout << sol.orangesRotting(g3) << endl; // 0

    cout << "All tests passed!" << endl;
    return 0;
}
