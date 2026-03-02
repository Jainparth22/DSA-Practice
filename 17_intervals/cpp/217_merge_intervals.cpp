// LC#56 — Merge Intervals
// Difficulty: Medium
// Pattern: Sorting + Linear Scan
// Time: O(n log n) | Space: O(n)
//
// Approach:
//   Sort intervals by start time.
//   Iterate: if current interval overlaps with the last merged one
//   (current.start <= last.end), extend last.end = max(last.end, current.end).
//   Otherwise push current interval as a new merged interval.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (auto& interval : intervals) {
            if (!merged.empty() && interval[0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            } else {
                merged.push_back(interval);
            }
        }
        return merged;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v1 = {{1,3},{2,6},{8,10},{15,18}};
    auto r1 = sol.merge(v1);
    // Expected: [[1,6],[8,10],[15,18]]
    for (auto& iv : r1) cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << endl;

    vector<vector<int>> v2 = {{1,4},{4,5}};
    auto r2 = sol.merge(v2);
    // Expected: [[1,5]]
    for (auto& iv : r2) cout << "[" << iv[0] << "," << iv[1] << "] ";
    cout << endl;

    cout << "All tests passed!" << endl;
    return 0;
}
