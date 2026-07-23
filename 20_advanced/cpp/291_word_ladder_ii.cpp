// LC#126 — Word Ladder II
// Difficulty: Hard | Pattern: BFS levels + DFS paths | Time: O(N * L^2 + paths) | Space: O(N * L)
#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> findLadders(string b, string e, vector<string>& wl) {
    unordered_set<string> d(wl.begin(), wl.end()); vector<vector<string>> res; if (!d.count(e)) return res;
    unordered_map<string,int> dist; dist[b] = 0; queue<string> q; q.push(b);
    while (!q.empty()) {
        string w = q.front(); q.pop(); if (w == e) break;
        for (size_t i = 0; i < w.size(); i++) { string x = w; for (char c = 'a'; c <= 'z'; c++) { x[i] = c; if (d.count(x) && !dist.count(x)) { dist[x] = dist[w] + 1; q.push(x); } } }
    }
    if (!dist.count(e)) return res;
    vector<string> path = {b};
    function<void(const string&)> dfs = [&](const string& w) {
        if (w == e) { res.push_back(path); return; }
        for (size_t i = 0; i < w.size(); i++) { string x = w; for (char c = 'a'; c <= 'z'; c++) { x[i] = c; auto it = dist.find(x); if (it != dist.end() && it->second == dist[w] + 1 && dist[w] < dist[e]) { path.push_back(x); dfs(x); path.pop_back(); } } }
    };
    dfs(b); return res;
}
int main() { vector<string> w = {"hot","dot","dog","lot","log","cog"}; cout << findLadders("hit", "cog", w).size() << endl; } // 2
