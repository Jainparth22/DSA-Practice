// LC#1024 — Video Stitching
// Difficulty: Medium | Pattern: Greedy | Time: O(n log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int videoStitching(vector<vector<int>>& c, int t) {
    sort(c.begin(), c.end()); int cnt = 0, end = 0, far = 0, i = 0;
    while (end < t) { while (i < (int)c.size() && c[i][0] <= end) far = max(far, c[i++][1]); if (far == end) return -1; end = far; cnt++; }
    return cnt;
}
int main() { vector<vector<int>> c = {{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}}; cout << videoStitching(c, 10) << endl; } // 3
