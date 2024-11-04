/*
 * LC #238 — Product of Array Except Self
 * Difficulty : Medium
 * Pattern    : Prefix Product + Suffix Product
 * Time       : O(n)
 * Space      : O(1) extra (output array doesn't count)
 *
 * Approach:
 *   Pass 1 (left to right): result[i] = product of all elements to the LEFT of i
 *   Pass 2 (right to left): multiply result[i] by product of all elements to the RIGHT of i
 *   No division used — handles zeros correctly.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        // Pass 1: result[i] = product of nums[0..i-1]
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];
        }

        // Pass 2: multiply result[i] by product of nums[i+1..n-1]
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> n1 = {1, 2, 3, 4};
    auto r1 = sol.productExceptSelf(n1);
    // Expected: [24, 12, 8, 6]
    for (int x : r1) cout << x << " "; cout << "\n";

    vector<int> n2 = {-1, 1, 0, -3, 3};
    auto r2 = sol.productExceptSelf(n2);
    // Expected: [0, 0, 9, 0, 0]
    for (int x : r2) cout << x << " "; cout << "\n";

    return 0;
}
