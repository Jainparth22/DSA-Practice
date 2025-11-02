/*
 * LC #242 — Valid Anagram
 * Difficulty : Easy
 * Pattern    : Frequency Count (Hash Map)
 * Time       : O(n)
 * Space      : O(1) — fixed 26-char alphabet
 *
 * Approach:
 *   Count character frequencies in s, then decrement for t.
 *   If any count ≠ 0 at the end, not an anagram.
 *   Alternative: sort both strings, compare — O(n log n).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int count[26] = {};
        for (char c : s) count[c - 'a']++;
        for (char c : t) {
            if (--count[c - 'a'] < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << boolalpha;
    cout << sol.isAnagram("anagram", "nagaram") << "\n"; // true
    cout << sol.isAnagram("rat", "car") << "\n";          // false
    cout << sol.isAnagram("a", "a") << "\n";              // true
    cout << sol.isAnagram("ab", "a") << "\n";             // false
    return 0;
}
