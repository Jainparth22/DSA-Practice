// LC#488 — Zuma Game
// Difficulty: Hard | Pattern: BFS over states | Time: exponential (small input) | Space: O(states)
#include <bits/stdc++.h>
using namespace std;
string shrink(string s) {
    for (int i = 0; i < (int)s.size();) { int j = i; while (j < (int)s.size() && s[j] == s[i]) j++; if (j - i >= 3) { s.erase(i, j - i); i = 0; } else i = j; }
    return s;
}
int findMinStep(string board, string hand) {
    sort(hand.begin(), hand.end()); queue<tuple<string,string,int>> q; set<pair<string,string>> seen; q.push({board, hand, 0}); seen.insert({board, hand});
    while (!q.empty()) {
        auto [b, h, d] = q.front(); q.pop();
        for (int i = 0; i < (int)h.size(); i++) {
            if (i && h[i] == h[i-1]) continue;
            for (int j = 0; j <= (int)b.size(); j++) {
                string nb = shrink(b.substr(0, j) + h[i] + b.substr(j)), nh = h.substr(0, i) + h.substr(i + 1);
                if (nb.empty()) return d + 1;
                if (seen.insert({nb, nh}).second) q.push({nb, nh, d + 1});
            }
        }
    }
    return -1;
}
int main() { cout << findMinStep("WRRBBW", "RB") << findMinStep("WWRRBBWW", "WRBRW") << endl; } // -12
