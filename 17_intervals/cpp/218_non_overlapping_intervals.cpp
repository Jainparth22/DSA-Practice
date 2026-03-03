// LC#435 — Non-overlapping Intervals
// Difficulty: Medium | Pattern: Greedy sort by end | Time: O(n log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int eraseOverlapIntervals(vector<vector<int>>& v) {
    sort(v.begin(), v.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
    int cnt = 0, end = INT_MIN;
    for (auto& x : v) { if (x[0] >= end) end = x[1]; else cnt++; }
    return cnt;
}
int main() { vector<vector<int>> v = {{1,2},{2,3},{3,4},{1,3}}; cout << eraseOverlapIntervals(v) << endl; } // 1
