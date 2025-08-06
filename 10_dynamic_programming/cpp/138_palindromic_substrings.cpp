// LC#647 — Palindromic Substrings
// Difficulty: Medium | Pattern: Expand Around Center | Time: O(n^2) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int countSubstrings(string s) {
    int n = s.size(), cnt = 0;
    for (int c = 0; c < 2 * n - 1; c++) {
        int l = c / 2, r = l + c % 2;
        while (l >= 0 && r < n && s[l] == s[r]) { cnt++; l--; r++; }
    }
    return cnt;
}
int main() { cout << countSubstrings("aaa") << endl; } // 6
