// LC#289 — Game of Life
// Difficulty: Medium | Pattern: In-place state encoding | Time: O(mn) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
void gameOfLife(vector<vector<int>>& b) {
    int R = b.size(), C = b[0].size();
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) {
        int n = 0;
        for (int x = max(0, i-1); x <= min(R-1, i+1); x++) for (int y = max(0, j-1); y <= min(C-1, j+1); y++) if ((x != i || y != j) && (b[x][y] & 1)) n++;
        if (b[i][j] && (n == 2 || n == 3)) b[i][j] |= 2;
        if (!b[i][j] && n == 3) b[i][j] |= 2;
    }
    for (auto& r : b) for (int& c : r) c >>= 1;
}
int main() { vector<vector<int>> b = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}}; gameOfLife(b); for (int x : b[1]) cout << x; } // 101
