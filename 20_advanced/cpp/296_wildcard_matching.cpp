// LC#44 — Wildcard Matching
// Difficulty: Hard | Pattern: Greedy two pointers | Time: O(mn) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) {
    int i = 0, j = 0, star = -1, mark = 0;
    while (i < (int)s.size()) {
        if (j < (int)p.size() && (p[j] == '?' || p[j] == s[i])) { i++; j++; }
        else if (j < (int)p.size() && p[j] == '*') { star = j++; mark = i; }
        else if (star >= 0) { j = star + 1; i = ++mark; }
        else return false;
    }
    while (j < (int)p.size() && p[j] == '*') j++;
    return j == (int)p.size();
}
int main() { cout << isMatch("adceb", "*a*b") << isMatch("acdcb", "a*c?b") << endl; } // 10
