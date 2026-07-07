// LC#1235 — Maximum Profit in Job Scheduling
// Difficulty: Hard | Pattern: Sort + DP + Binary Search | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
    int n = s.size(); vector<int> id(n); iota(id.begin(), id.end(), 0); sort(id.begin(), id.end(), [&](int a, int b) { return e[a] < e[b]; });
    vector<int> ends, best = {0};
    for (int i : id) {
        int k = upper_bound(ends.begin(), ends.end(), s[i]) - ends.begin();
        int v = max(best.back(), best[k] + p[i]); ends.push_back(e[i]); best.push_back(v);
    }
    return best.back();
}
int main() { vector<int> s = {1,2,3,3}, e = {3,4,5,6}, p = {50,10,40,70}; cout << jobScheduling(s, e, p) << endl; } // 120
