// LC#5 — Longest Palindromic Substring
// Difficulty: Medium | Pattern: Expand Around Center | Time: O(n^2) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
    int n = s.size(), bs = 0, bl = 0;
    for (int c = 0; c < 2 * n - 1; c++) {
        int l = c / 2, r = l + c % 2;
        while (l >= 0 && r < n && s[l] == s[r]) { l--; r++; }
        if (r - l - 1 > bl) { bl = r - l - 1; bs = l + 1; }
    }
    return s.substr(bs, bl);
}
int main() { cout << longestPalindrome("babad") << endl; } // bab
