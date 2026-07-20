// LC#269 — Alien Dictionary
// Difficulty: Hard | Pattern: Topological Sort | Time: O(C) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
string alienOrder(vector<string>& w) {
    map<char, set<char>> g; map<char, int> indeg;
    for (auto& s : w) for (char c : s) indeg[c];
    for (size_t i = 0; i + 1 < w.size(); i++) {
        auto &a = w[i], &b = w[i+1]; size_t k = 0, m = min(a.size(), b.size());
        while (k < m && a[k] == b[k]) k++;
        if (k == m) { if (a.size() > b.size()) return ""; continue; }
        if (g[a[k]].insert(b[k]).second) indeg[b[k]]++;
    }
    queue<char> q; string res;
    for (auto& [c, d] : indeg) if (!d) q.push(c);
    while (!q.empty()) { char c = q.front(); q.pop(); res += c; for (char n : g[c]) if (!--indeg[n]) q.push(n); }
    return res.size() == indeg.size() ? res : "";
}
int main() { vector<string> w = {"wrt","wrf","er","ett","rftt"}; cout << alienOrder(w) << endl; } // wertf
