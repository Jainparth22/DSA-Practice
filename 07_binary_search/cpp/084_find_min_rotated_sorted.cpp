// LC#153 — Find Minimum in Rotated Sorted Array
// Difficulty: Medium
// Pattern: Binary Search
// Time: O(log n) | Space: O(1)
//
// Approach:
//   The minimum is always in the UNSORTED half.
//   If nums[mid] > nums[right]: min is in right half → left = mid + 1.
//   Else: min is in left half (including mid) → right = mid.
//   Loop ends when left == right, pointing at minimum.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {3, 4, 5, 1, 2};
    cout << sol.findMin(v1) << endl; // 1

    vector<int> v2 = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.findMin(v2) << endl; // 0

    vector<int> v3 = {11, 13, 15, 17};
    cout << sol.findMin(v3) << endl; // 11 (not rotated)

    vector<int> v4 = {2, 1};
    cout << sol.findMin(v4) << endl; // 1

    cout << "All tests passed!" << endl;
    return 0;
}
