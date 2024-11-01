/*
 * LC #1 — Two Sum
 * Difficulty : Easy
 * Pattern    : Hash Map
 * Time       : O(n)
 * Space      : O(n)
 *
 * Approach:
 *   For each element nums[i], check if (target - nums[i]) already exists in
 *   the hash map. If yes, return the two indices. Otherwise store nums[i]->i.
 *   Single pass, never need to look at an element twice.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index
        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {}; // guaranteed by problem constraints to have a solution
    }
};

int main() {
    Solution sol;

    // Test 1: basic
    vector<int> nums1 = {2, 7, 11, 15};
    auto res1 = sol.twoSum(nums1, 9);
    cout << "[" << res1[0] << ", " << res1[1] << "]\n"; // [0, 1]

    // Test 2: answer not at index 0
    vector<int> nums2 = {3, 2, 4};
    auto res2 = sol.twoSum(nums2, 6);
    cout << "[" << res2[0] << ", " << res2[1] << "]\n"; // [1, 2]

    // Test 3: same element used twice (different indices)
    vector<int> nums3 = {3, 3};
    auto res3 = sol.twoSum(nums3, 6);
    cout << "[" << res3[0] << ", " << res3[1] << "]\n"; // [0, 1]

    return 0;
}
