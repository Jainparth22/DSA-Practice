// LC#127 — Word Ladder
// Difficulty: Hard | Pattern: BFS | Time: O(N * L^2) | Space: O(N * L)
#include <bits/stdc++.h>
using namespace std;
int ladderLength(string b, string e, vector<string>& words) {
    unordered_set<string> dict(words.begin(), words.end());
    if (!dict.count(e)) return 0;
    queue<pair<string,int>> q; q.push({b, 1});
    while (!q.empty()) {
        auto [w, d] = q.front(); q.pop();
        if (w == e) return d;
        for (size_t i = 0; i < w.size(); i++) {
            char o = w[i];
            for (char c = 'a'; c <= 'z'; c++) { w[i] = c; if (dict.count(w)) { dict.erase(w); q.push({w, d + 1}); } }
            w[i] = o;
        }
    }
    return 0;
}
int main() { vector<string> w = {"hot","dot","dog","lot","log","cog"}; cout << ladderLength("hit", "cog", w) << endl; } // 5
