// LC#73 — Set Matrix Zeroes
// Difficulty: Medium | Pattern: In-place markers | Time: O(mn) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& m) {
    int R = m.size(), C = m[0].size(); bool r0 = false, c0 = false;
    for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) if (!m[i][j]) { if (!i) r0 = true; if (!j) c0 = true; m[i][0] = m[0][j] = 0; }
    for (int i = 1; i < R; i++) for (int j = 1; j < C; j++) if (!m[i][0] || !m[0][j]) m[i][j] = 0;
    if (r0) for (int j = 0; j < C; j++) m[0][j] = 0;
    if (c0) for (int i = 0; i < R; i++) m[i][0] = 0;
}
int main() { vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}}; setZeroes(m); cout << m[1][1] << m[0][1] << endl; } // 00
