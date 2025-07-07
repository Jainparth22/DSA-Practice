// LC#130 — Surrounded Regions
// Difficulty: Medium | Pattern: Border DFS | Time: O(mn) | Space: O(mn)
#include <bits/stdc++.h>
using namespace std;
void mark(vector<vector<char>>& b, int i, int j) {
    if (i < 0 || j < 0 || i >= (int)b.size() || j >= (int)b[0].size() || b[i][j] != 'O') return;
    b[i][j] = 'T'; mark(b, i+1, j); mark(b, i-1, j); mark(b, i, j+1); mark(b, i, j-1);
}
void solve(vector<vector<char>>& b) {
    int R = b.size(), C = b[0].size();
    for (int i = 0; i < R; i++) { mark(b, i, 0); mark(b, i, C - 1); }
    for (int j = 0; j < C; j++) { mark(b, 0, j); mark(b, R - 1, j); }
    for (auto& r : b) for (char& c : r) c = c == 'T' ? 'O' : 'X';
}
int main() { vector<vector<char>> b = {{'X','X','X'},{'X','O','X'},{'X','X','X'}}; solve(b); cout << b[1][1] << endl; } // X
