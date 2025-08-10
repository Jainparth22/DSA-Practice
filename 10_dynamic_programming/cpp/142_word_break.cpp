// LC#139 — Word Break
// Difficulty: Medium | Pattern: 1D DP | Time: O(n^2) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
bool wordBreak(string s, vector<string>& w) {
    unordered_set<string> d(w.begin(), w.end()); int n = s.size(); vector<bool> dp(n + 1); dp[0] = true;
    for (int i = 1; i <= n; i++) for (int j = 0; j < i && !dp[i]; j++) dp[i] = dp[j] && d.count(s.substr(j, i - j));
    return dp[n];
}
int main() { vector<string> w = {"leet","code"}; cout << wordBreak("leetcode", w) << endl; } // 1
