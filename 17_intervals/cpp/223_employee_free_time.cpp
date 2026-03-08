// LC#759 — Employee Free Time
// Difficulty: Hard | Pattern: Merge intervals | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& s) {
    vector<vector<int>> all; for (auto& e : s) for (auto& x : e) all.push_back(x);
    sort(all.begin(), all.end()); vector<vector<int>> res; int end = all[0][1];
    for (auto& x : all) { if (x[0] > end) res.push_back({end, x[0]}); end = max(end, x[1]); }
    return res;
}
int main() { vector<vector<vector<int>>> s = {{{1,2},{5,6}},{{1,3}},{{4,10}}}; auto r = employeeFreeTime(s); cout << r.size() << r[0][0] << r[0][1] << endl; } // 134
