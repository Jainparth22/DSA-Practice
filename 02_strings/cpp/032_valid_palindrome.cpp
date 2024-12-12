/*
 * LC #125 — Valid Palindrome
 * Difficulty : Easy
 * Pattern    : Two Pointers
 * Time       : O(n)
 * Space      : O(1)
 *
 * Approach:
 *   Two pointers (left, right). Skip non-alphanumeric chars.
 *   Compare lowercased characters. If ever mismatch → false.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++; r--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << "\n"; // true
    cout << sol.isPalindrome("race a car") << "\n";                       // false
    cout << sol.isPalindrome(" ") << "\n";                                // true
    cout << sol.isPalindrome("0P") << "\n";                               // false
    return 0;
}
