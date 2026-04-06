/*
 * LC #200 — Number of Islands
 * Difficulty : Medium
 * Pattern    : Graph — DFS Flood Fill
 * Time       : O(m × n)
 * Space      : O(m × n) recursion stack
 *
 * Approach:
 *   For each unvisited '1', increment count and DFS to mark all connected
 *   land cells as visited (replace '1' with '0' in-place, or use a visited array).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;
        grid[r][c] = '0'; // mark visited
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int r = 0; r < (int)grid.size(); r++)
            for (int c = 0; c < (int)grid[0].size(); c++)
                if (grid[r][c] == '1') { count++; dfs(grid, r, c); }
        return count;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> g1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << sol.numIslands(g1) << "\n"; // 1

    vector<vector<char>> g2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << sol.numIslands(g2) << "\n"; // 3

    return 0;
}
