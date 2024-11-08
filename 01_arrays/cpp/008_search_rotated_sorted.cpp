// LC#33 — Search in Rotated Sorted Array
// Difficulty: Medium
// Pattern: Binary Search
// Time: O(log n) | Space: O(1)
//
// Approach:
//   At every mid, one half is always sorted. Determine which.
//   If LEFT half sorted: check if target lies in [left, mid] range.
//     Yes → right = mid - 1. No → left = mid + 1.
//   If RIGHT half sorted: check if target lies in [mid, right] range.
//     Yes → left = mid + 1. No → right = mid - 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.search(v1, 0) << endl; // 4
    cout << sol.search(v1, 3) << endl; // -1

    vector<int> v2 = {1};
    cout << sol.search(v2, 0) << endl; // -1

    vector<int> v3 = {3, 1};
    cout << sol.search(v3, 1) << endl; // 1

    cout << "All tests passed!" << endl;
    return 0;
}
