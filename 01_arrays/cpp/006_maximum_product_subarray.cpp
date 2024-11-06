// LC#152 — Maximum Product Subarray
// Difficulty: Medium
// Pattern: Dynamic Programming / Greedy
// Time: O(n) | Space: O(1)
//
// Approach:
//   Track both curMax AND curMin at each step, because multiplying a
//   negative minimum by another negative gives a new maximum.
//   At each element: new_max = max(num, num*curMax, num*curMin)
//                    new_min = min(num, num*curMax, num*curMin)
//   Update global result with curMax at each step.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0], curMin = nums[0], result = nums[0];
        for (int i = 1; i < (int)nums.size(); i++) {
            int num = nums[i];
            int tempMax = max({num, curMax * num, curMin * num});
            int tempMin = min({num, curMax * num, curMin * num});
            curMax = tempMax;
            curMin = tempMin;
            result = max(result, curMax);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {2, 3, -2, 4};
    cout << sol.maxProduct(v1) << endl; // 6 ([2,3])

    vector<int> v2 = {-2, 0, -1};
    cout << sol.maxProduct(v2) << endl; // 0

    vector<int> v3 = {-2, 3, -4};
    cout << sol.maxProduct(v3) << endl; // 24 (all three)

    vector<int> v4 = {-2};
    cout << sol.maxProduct(v4) << endl; // -2

    cout << "All tests passed!" << endl;
    return 0;
}
