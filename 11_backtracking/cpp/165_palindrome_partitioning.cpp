// LC#131 — Palindrome Partitioning
// Difficulty: Medium | Pattern: Backtracking | Time: O(n * 2^n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
bool pal(const string& s, int l, int r) { while (l < r) if (s[l++] != s[r--]) return false; return true; }
void go(const string& s, int i, vector<string>& cur, vector<vector<string>>& res) {
    if (i == (int)s.size()) { res.push_back(cur); return; }
    for (int j = i; j < (int)s.size(); j++) if (pal(s, i, j)) { cur.push_back(s.substr(i, j - i + 1)); go(s, j + 1, cur, res); cur.pop_back(); }
}
vector<vector<string>> partition(string s) { vector<vector<string>> res; vector<string> cur; go(s, 0, cur, res); return res; }
int main() { cout << partition("aab").size() << endl; } // 2
