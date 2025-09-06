// LC#47 — Permutations II
// Difficulty: Medium | Pattern: Backtracking + used[] | Time: O(n * n!) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
void go(vector<int>& a, vector<bool>& used, vector<int>& cur, vector<vector<int>>& res) {
    if (cur.size() == a.size()) { res.push_back(cur); return; }
    for (int i = 0; i < (int)a.size(); i++) {
        if (used[i] || (i && a[i] == a[i-1] && !used[i-1])) continue;
        used[i] = true; cur.push_back(a[i]); go(a, used, cur, res); cur.pop_back(); used[i] = false;
    }
}
vector<vector<int>> permuteUnique(vector<int>& a) { sort(a.begin(), a.end()); vector<vector<int>> res; vector<int> cur; vector<bool> used(a.size()); go(a, used, cur, res); return res; }
int main() { vector<int> a = {1,1,2}; cout << permuteUnique(a).size() << endl; } // 3
