// LC#727 — Minimum Window Subsequence
// Difficulty: Hard | Pattern: Two pointers (forward/backward) | Time: O(mn) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    int n = s.size(), m = t.size(), best = INT_MAX, bs = 0, i = 0;
    while (i < n) {
        int j = 0;
        while (i < n) { if (s[i] == t[j] && ++j == m) break; i++; }
        if (i == n) break;
        int end = i; j = m - 1;
        while (j >= 0) { if (s[i] == t[j]) j--; i--; }
        i++;
        if (end - i + 1 < best) { best = end - i + 1; bs = i; }
        i++;
    }
    return best == INT_MAX ? "" : s.substr(bs, best);
}
int main() { cout << minWindow("abcdebdde", "bde") << endl; } // bcde
