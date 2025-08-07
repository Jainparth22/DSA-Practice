// LC#91 — Decode Ways
// Difficulty: Medium | Pattern: 1D DP | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int numDecodings(string s) {
    int n = s.size(), a = 1, b = s[0] != '0';  // a = dp[i-2], b = dp[i-1]
    for (int i = 2; i <= n; i++) {
        int c = 0, one = s[i-1] - '0', two = stoi(s.substr(i - 2, 2));
        if (one) c += b; if (two >= 10 && two <= 26) c += a;
        a = b; b = c;
    }
    return b;
}
int main() { cout << numDecodings("226") << numDecodings("06") << endl; } // 30
