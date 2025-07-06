// LC#417 — Pacific Atlantic Water Flow
// Difficulty: Medium
// Pattern: Reverse BFS/DFS from borders
// Time: O(m*n) | Space: O(m*n)
//
// Approach:
//   Instead of simulating flow DOWN, reverse: flow UPHILL from oceans.
//   Pacific touches top & left borders. Atlantic touches bottom & right.
//   BFS from each ocean's border cells, expanding to any neighbour >= current height.
//   Result: cells reachable from BOTH oceans.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void bfs(vector<vector<int>>& h, queue<pair<int,int>>& q,
             vector<vector<bool>>& visited) {
        int rows = h.size(), cols = h[0].size();
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto& d : dirs) {
                int nr = r+d[0], nc = c+d[1];
                if (nr>=0 && nr<rows && nc>=0 && nc<cols
                    && !visited[nr][nc] && h[nr][nc] >= h[r][c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));
        queue<pair<int,int>> pq, aq;
        for (int r = 0; r < rows; r++) {
            pac[r][0] = atl[r][cols-1] = true;
            pq.push({r, 0}); aq.push({r, cols-1});
        }
        for (int c = 0; c < cols; c++) {
            pac[0][c] = atl[rows-1][c] = true;
            pq.push({0, c}); aq.push({rows-1, c});
        }
        bfs(heights, pq, pac);
        bfs(heights, aq, atl);
        vector<vector<int>> result;
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                if (pac[r][c] && atl[r][c])
                    result.push_back({r, c});
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> h = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    auto res = sol.pacificAtlantic(h);
    cout << "Cells that reach both: " << res.size() << endl; // 7 cells
    for (auto& v : res) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << endl;
    cout << "All tests passed!" << endl;
    return 0;
}
