/*
 * LC #136 — Single Number
 * Difficulty : Easy
 * Pattern    : Bit Manipulation — XOR
 * Time       : O(n)
 * Space      : O(1)
 *
 * Key insight:
 *   a ^ a = 0  (XOR with self = 0)
 *   a ^ 0 = a  (XOR with 0 = self)
 *   XOR is commutative and associative.
 *   All duplicates cancel out → only the single number remains.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int n : nums) result ^= n;
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> n1 = {2, 2, 1};          cout << sol.singleNumber(n1) << "\n"; // 1
    vector<int> n2 = {4, 1, 2, 1, 2};    cout << sol.singleNumber(n2) << "\n"; // 4
    vector<int> n3 = {1};                 cout << sol.singleNumber(n3) << "\n"; // 1
    vector<int> n4 = {0, 1, 0};           cout << sol.singleNumber(n4) << "\n"; // 1
    return 0;
}
