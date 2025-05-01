/*
 * LC #704 — Binary Search
 * Difficulty : Easy
 * Pattern    : Binary Search (standard)
 * Time       : O(log n)
 * Space      : O(1)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if      (nums[mid] == target) return mid;
            else if (nums[mid] < target)  lo = mid + 1;
            else                          hi = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> n1 = {-1, 0, 3, 5, 9, 12};
    cout << sol.search(n1, 9)  << "\n"; // 4
    cout << sol.search(n1, 2)  << "\n"; // -1
    cout << sol.search(n1, -1) << "\n"; // 0
    cout << sol.search(n1, 12) << "\n"; // 5
    return 0;
}
