// LC#55 — Jump Game
// Difficulty: Medium
// Pattern: Greedy
// Time: O(n) | Space: O(1)
//
// Approach:
//   Track the farthest index we can reach (maxReach).
//   At each index i, if i > maxReach we're stuck — return false.
//   Otherwise update maxReach = max(maxReach, i + nums[i]).
//   If we process all indices without getting stuck, return true.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {2, 3, 1, 1, 4};
    cout << sol.canJump(v1) << endl; // 1 (true)

    vector<int> v2 = {3, 2, 1, 0, 4};
    cout << sol.canJump(v2) << endl; // 0 (false)

    vector<int> v3 = {0};
    cout << sol.canJump(v3) << endl; // 1 (true)

    cout << "All tests passed!" << endl;
    return 0;
}
