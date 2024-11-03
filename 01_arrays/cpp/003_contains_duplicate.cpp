/*
 * LC #217 — Contains Duplicate
 * Difficulty : Easy
 * Pattern    : Hash Set
 * Time       : O(n)
 * Space      : O(n)
 *
 * Approach:
 *   Insert each element into an unordered_set.
 *   If the element already exists in the set, return true.
 *   If we exhaust the array without a hit, return false.
 *
 * Alternative O(n log n) / O(1) space: sort and check adjacent elements.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n : nums) {
            if (seen.count(n)) return true;
            seen.insert(n);
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> v1 = {1, 2, 3, 1};
    cout << boolalpha << sol.containsDuplicate(v1) << "\n"; // true

    vector<int> v2 = {1, 2, 3, 4};
    cout << sol.containsDuplicate(v2) << "\n"; // false

    vector<int> v3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << sol.containsDuplicate(v3) << "\n"; // true

    return 0;
}
