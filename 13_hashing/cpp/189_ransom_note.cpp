// LC#383 — Ransom Note
// Difficulty: Easy | Pattern: Frequency count | Time: O(m+n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
bool canConstruct(string r, string m) {
    int cnt[26] = {};
    for (char c : m) cnt[c - 'a']++;
    for (char c : r) if (--cnt[c - 'a'] < 0) return false;
    return true;
}
int main() { cout << canConstruct("a", "b") << canConstruct("aa", "aab") << endl; } // 01
