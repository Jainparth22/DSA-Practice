// LC#40 — Combination Sum II
// Difficulty: Medium | Pattern: Backtracking + skip duplicates | Time: O(2^n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
void go(vector<int>& a, int i, int rem, vector<int>& cur, vector<vector<int>>& res) {
    if (!rem) { res.push_back(cur); return; }
    for (int j = i; j < (int)a.size() && a[j] <= rem; j++) { if (j > i && a[j] == a[j-1]) continue; cur.push_back(a[j]); go(a, j + 1, rem - a[j], cur, res); cur.pop_back(); }
}
vector<vector<int>> combinationSum2(vector<int>& a, int t) { sort(a.begin(), a.end()); vector<vector<int>> res; vector<int> cur; go(a, 0, t, cur, res); return res; }
int main() { vector<int> a = {10,1,2,7,6,1,5}; cout << combinationSum2(a, 8).size() << endl; } // 4
