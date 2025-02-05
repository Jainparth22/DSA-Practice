// LC#76 — Minimum Window Substring
// Difficulty: Hard | Pattern: Sliding Window | Time: O(n) | Space: O(k)
#include <bits/stdc++.h>
using namespace std;
string minWindow(string s, string t) {
    vector<int> need(128, 0); int missing = t.size();
    for (char c : t) need[c]++;
    int best = INT_MAX, bs = 0, l = 0;
    for (int r = 0; r < (int)s.size(); r++) {
        if (need[s[r]]-- > 0) missing--;
        while (!missing) {
            if (r - l + 1 < best) { best = r - l + 1; bs = l; }
            if (++need[s[l++]] > 0) missing++;
        }
    }
    return best == INT_MAX ? "" : s.substr(bs, best);
}
int main() { cout << minWindow("ADOBECODEBANC", "ABC") << endl; } // BANC
