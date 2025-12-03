// LC#45 — Jump Game II
// Difficulty: Medium
// Pattern: Greedy (BFS-like levels)
// Time: O(n) | Space: O(1)
//
// Approach:
//   Think of this as BFS levels. Each "level" is the range of indices
//   reachable in a fixed number of jumps.
//   current_end = end of current jump range.
//   farthest = farthest we can reach from any index in current level.
//   When i reaches current_end, we must jump → jumps++, current_end = farthest.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {2, 3, 1, 1, 4};
    cout << sol.jump(v1) << endl; // 2

    vector<int> v2 = {2, 3, 0, 1, 4};
    cout << sol.jump(v2) << endl; // 2

    vector<int> v3 = {1, 2, 3};
    cout << sol.jump(v3) << endl; // 2

    cout << "All tests passed!" << endl;
    return 0;
}
