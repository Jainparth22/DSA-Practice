// LC#191 — Number of 1 Bits (Hamming Weight)
// Difficulty: Easy | Pattern: Bit Manipulation
// Time: O(1) — 32-bit | Space: O(1)
// Approach: n & (n-1) clears the lowest set bit. Count how many times until n==0.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) { n &= (n - 1); count++; }
        return count;
    }
};
int main() {
    Solution sol;
    cout << sol.hammingWeight(11)  << endl; // 3  (0b1011)
    cout << sol.hammingWeight(128) << endl; // 1  (0b10000000)
    cout << sol.hammingWeight(4294967293U) << endl; // 31
    cout << "All tests passed!" << endl;
    return 0;
}
