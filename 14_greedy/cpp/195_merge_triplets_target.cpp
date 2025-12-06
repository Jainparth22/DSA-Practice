// LC#1899 — Merge Triplets to Form Target
// Difficulty: Medium | Pattern: Greedy filter | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
bool mergeTriplets(vector<vector<int>>& t, vector<int>& target) {
    bool g[3] = {};
    for (auto& x : t) if (x[0] <= target[0] && x[1] <= target[1] && x[2] <= target[2]) for (int i = 0; i < 3; i++) if (x[i] == target[i]) g[i] = true;
    return g[0] && g[1] && g[2];
}
int main() { vector<vector<int>> t = {{2,5,3},{1,8,4},{1,7,5}}; vector<int> tg = {2,7,5}; cout << mergeTriplets(t, tg) << endl; } // 1
