// LC#1334 — Find the City With Fewest Neighbors
// Difficulty: Medium | Pattern: Floyd-Warshall | Time: O(n^3) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
int findTheCity(int n, vector<vector<int>>& e, int th) {
    vector<vector<int>> d(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++) d[i][i] = 0;
    for (auto& x : e) d[x[0]][x[1]] = d[x[1]][x[0]] = x[2];
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int best = -1, bc = INT_MAX;
    for (int i = 0; i < n; i++) { int c = 0; for (int j = 0; j < n; j++) c += d[i][j] <= th; if (c <= bc) { bc = c; best = i; } }
    return best;
}
int main() { vector<vector<int>> e = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}}; cout << findTheCity(4, e, 4) << endl; } // 3
