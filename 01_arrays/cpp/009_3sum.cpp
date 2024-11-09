/*
 * LC #15 — 3Sum
 * Difficulty : Medium
 * Pattern    : Sort + Two Pointers
 * Time       : O(n²)
 * Space      : O(1) extra (excluding output)
 *
 * Approach:
 *   Sort the array. For each index i, use two pointers l=i+1 and r=n-1.
 *   Skip duplicates at each level to avoid duplicate triplets.
 *   If nums[i]+nums[l]+nums[r] == 0: add, advance both pointers (skip dups).
 *   If sum < 0: move l right. If sum > 0: move r left.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // skip dup i
            if (nums[i] > 0) break;  // all remaining positive, can't sum to 0

            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l+1]) l++; // skip dup l
                    while (l < r && nums[r] == nums[r-1]) r--; // skip dup r
                    l++; r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> n1 = {-1, 0, 1, 2, -1, -4};
    auto r1 = sol.threeSum(n1);
    // Expected: [[-1,-1,2],[-1,0,1]]
    for (auto& t : r1) cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    cout << "\n";

    vector<int> n2 = {0, 1, 1};
    auto r2 = sol.threeSum(n2);
    cout << (r2.empty() ? "[]" : "non-empty") << "\n"; // []

    vector<int> n3 = {0, 0, 0};
    auto r3 = sol.threeSum(n3);
    for (auto& t : r3) cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    cout << "\n"; // [[0,0,0]]

    return 0;
}
