// LC#452 — Minimum Number of Arrows to Burst Balloons
// Difficulty: Medium | Pattern: Greedy sort by end | Time: O(n log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int findMinArrowShots(vector<vector<int>>& p) {
    sort(p.begin(), p.end(), [](auto& a, auto& b) { return a[1] < b[1]; });
    int arrows = 0; long long end = LLONG_MIN;
    for (auto& x : p) if (x[0] > end) { arrows++; end = x[1]; }
    return arrows;
}
int main() { vector<vector<int>> p = {{10,16},{2,8},{1,6},{7,12}}; cout << findMinArrowShots(p) << endl; } // 2
