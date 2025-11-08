// LC#128 — Longest Consecutive Sequence
// Difficulty: Medium
// Pattern: Hash Set
// Time: O(n) | Space: O(n)
//
// Approach:
//   Insert all numbers into a hash set for O(1) lookup.
//   For each number, only START counting if (num-1) is NOT in the set
//   (i.e., num is the beginning of a sequence).
//   Count how far the sequence extends by checking num+1, num+2, ...
//   Track the longest such run.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int num : numSet) {
            // only start from sequence beginning
            if (!numSet.count(num - 1)) {
                int current = num;
                int length = 1;
                while (numSet.count(current + 1)) {
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(v1) << endl; // 4 (1,2,3,4)

    vector<int> v2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << sol.longestConsecutive(v2) << endl; // 9

    vector<int> v3 = {};
    cout << sol.longestConsecutive(v3) << endl; // 0

    cout << "All tests passed!" << endl;
    return 0;
}
