// LC#986 — Interval List Intersections
// Difficulty: Medium | Pattern: Two Pointers | Time: O(m+n) | Space: O(m+n)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> r; size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        int lo = max(a[i][0], b[j][0]), hi = min(a[i][1], b[j][1]);
        if (lo <= hi) r.push_back({lo, hi});
        a[i][1] < b[j][1] ? i++ : j++;
    }
    return r;
}
int main() { vector<vector<int>> a = {{0,2},{5,10}}, b = {{1,5},{8,12}}; cout << intervalIntersection(a, b).size() << endl; } // 3
