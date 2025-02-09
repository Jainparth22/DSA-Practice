// LC#438 — Find All Anagrams in a String
// Difficulty: Medium | Pattern: Fixed Sliding Window | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p) {
    int m = p.size(), n = s.size(); vector<int> res;
    if (m > n) return res;
    vector<int> a(26), b(26);
    for (int i = 0; i < m; i++) { a[p[i]-'a']++; b[s[i]-'a']++; }
    if (a == b) res.push_back(0);
    for (int i = m; i < n; i++) {
        b[s[i]-'a']++; b[s[i-m]-'a']--;
        if (a == b) res.push_back(i - m + 1);
    }
    return res;
}
int main() { for (int x : findAnagrams("cbaebabacd", "abc")) cout << x << " "; } // 0 6
