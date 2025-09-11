// LC#37 — Sudoku Solver
// Difficulty: Hard | Pattern: Backtracking | Time: O(9^m) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
bool ok(vector<vector<char>>& b, int r, int c, char v) {
    for (int i = 0; i < 9; i++) if (b[r][i] == v || b[i][c] == v || b[3*(r/3) + i/3][3*(c/3) + i%3] == v) return false;
    return true;
}
bool solve(vector<vector<char>>& b) {
    for (int r = 0; r < 9; r++) for (int c = 0; c < 9; c++) if (b[r][c] == '.') {
        for (char v = '1'; v <= '9'; v++) if (ok(b, r, c, v)) { b[r][c] = v; if (solve(b)) return true; b[r][c] = '.'; }
        return false;
    }
    return true;
}
int main() {
    vector<string> s = {"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
    vector<vector<char>> b; for (auto& r : s) b.push_back(vector<char>(r.begin(), r.end()));
    solve(b); for (char c : b[0]) cout << c; cout << endl; } // 534678912
