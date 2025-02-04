// LC#567 — Permutation in String
// Difficulty: Medium | Pattern: Fixed Sliding Window | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
bool checkInclusion(string p, string s) {
    int m = p.size(); if (m > (int)s.size()) return false;
    vector<int> a(26), b(26);
    for (int i = 0; i < m; i++) { a[p[i]-'a']++; b[s[i]-'a']++; }
    if (a == b) return true;
    for (int i = m; i < (int)s.size(); i++) {
        b[s[i]-'a']++; b[s[i-m]-'a']--;
        if (a == b) return true;
    }
    return false;
}
int main() { cout << checkInclusion("ab", "eidbaooo") << endl; } // 1
