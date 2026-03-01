// LC#57 — Insert Interval
// Difficulty: Medium
// Pattern: Linear Scan + Merge
// Time: O(n) | Space: O(n)
//
// Approach:
//   Three phases:
//   1. Add all intervals that END before newInterval starts (no overlap).
//   2. Merge all intervals that OVERLAP with newInterval → extend newInterval.
//   3. Add all remaining intervals (start after merged newInterval ends).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // Phase 1: no overlap, interval ends before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i++]);
        }

        // Phase 2: overlap — merge into newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // Phase 3: remaining non-overlapping intervals
        while (i < n) {
            result.push_back(intervals[i++]);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v1 = {{1,3},{6,9}};
    vector<int> ni1 = {2, 5};
    auto r1 = sol.insert(v1, ni1);
    // Expected: [[1,5],[6,9]]
    for (auto& iv : r1) cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << endl;

    vector<vector<int>> v2 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> ni2 = {4, 8};
    auto r2 = sol.insert(v2, ni2);
    // Expected: [[1,2],[3,10],[12,16]]
    for (auto& iv : r2) cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << endl;

    cout << "All tests passed!" << endl;
    return 0;
}
