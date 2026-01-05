// LC#268 — Missing Number
// Difficulty: Easy | Pattern: XOR / Math
// Time: O(n) | Space: O(1)
// Approach: XOR all indices 0..n with all nums. Paired values cancel → result is missing.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < (int)nums.size(); i++)
            missing ^= i ^ nums[i];
        return missing;
    }
};
int main() {
    Solution sol;
    vector<int> v1 = {3,0,1};   cout << sol.missingNumber(v1) << endl; // 2
    vector<int> v2 = {0,1};     cout << sol.missingNumber(v2) << endl; // 2
    vector<int> v3 = {9,6,4,2,3,5,7,0,1}; cout << sol.missingNumber(v3) << endl; // 8
    cout << "All tests passed!" << endl;
    return 0;
}
