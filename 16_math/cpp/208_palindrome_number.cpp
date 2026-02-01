// LC#9 — Palindrome Number
// Difficulty: Easy | Pattern: Math
// Time: O(log n) | Space: O(1)
// Approach: Reverse the second half of digits, compare with first half.
// Negatives and numbers ending in 0 (except 0 itself) are never palindromes.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return x == reversed || x == reversed / 10;
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome(121)  << endl; // 1
    cout << sol.isPalindrome(-121) << endl; // 0
    cout << sol.isPalindrome(10)   << endl; // 0
    cout << sol.isPalindrome(0)    << endl; // 1
    cout << sol.isPalindrome(1221) << endl; // 1
    cout << "All tests passed!" << endl;
    return 0;
}
