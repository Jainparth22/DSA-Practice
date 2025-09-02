// LC#90 — Subsets II
// Difficulty: Medium | Pattern: Backtracking + skip duplicates | Time: O(n * 2^n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
void go(vector<int>& a, int i, vector<int>& cur, vector<vector<int>>& res) {
    res.push_back(cur);
    for (int j = i; j < (int)a.size(); j++) { if (j > i && a[j] == a[j-1]) continue; cur.push_back(a[j]); go(a, j + 1, cur, res); cur.pop_back(); }
}
vector<vector<int>> subsetsWithDup(vector<int>& a) { sort(a.begin(), a.end()); vector<vector<int>> res; vector<int> cur; go(a, 0, cur, res); return res; }
int main() { vector<int> a = {1,2,2}; cout << subsetsWithDup(a).size() << endl; } // 6
