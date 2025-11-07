// LC#560 — Subarray Sum Equals K
// Difficulty: Medium
// Pattern: Prefix Sum + Hash Map
// Time: O(n) | Space: O(n)
//
// Approach:
//   Keep a running prefix sum. For each index i, check how many
//   previous prefix sums equal (current_sum - k). That count is the
//   number of subarrays ending at i with sum == k.
//   Use a hash map: prefixCount[sum] = frequency.
//   Initialize with prefixCount[0] = 1 (empty subarray before start).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int runningSum = 0, count = 0;
        for (int num : nums) {
            runningSum += num;
            if (prefixCount.count(runningSum - k)) {
                count += prefixCount[runningSum - k];
            }
            prefixCount[runningSum]++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {1, 1, 1};
    cout << sol.subarraySum(v1, 2) << endl; // 2

    vector<int> v2 = {1, 2, 3};
    cout << sol.subarraySum(v2, 3) << endl; // 2

    vector<int> v3 = {-1, -1, 1};
    cout << sol.subarraySum(v3, -1) << endl; // 1 ([- 1] or [-1,-1,1])

    cout << "All tests passed!" << endl;
    return 0;
}
