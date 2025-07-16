// LC#743 — Network Delay Time
// Difficulty: Medium | Pattern: Dijkstra | Time: O(E log V) | Space: O(V+E)
#include <bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>>& t, int n, int k) {
    vector<vector<pair<int,int>>> g(n + 1); vector<int> d(n + 1, INT_MAX); d[k] = 0;
    for (auto& e : t) g[e[0]].push_back({e[1], e[2]});
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; pq.push({0, k});
    while (!pq.empty()) {
        auto [dist, u] = pq.top(); pq.pop();
        if (dist > d[u]) continue;
        for (auto [v, w] : g[u]) if (dist + w < d[v]) { d[v] = dist + w; pq.push({d[v], v}); }
    }
    int res = *max_element(d.begin() + 1, d.end());
    return res == INT_MAX ? -1 : res;
}
int main() { vector<vector<int>> t = {{2,1,1},{2,3,1},{3,4,1}}; cout << networkDelayTime(t, 4, 2) << endl; } // 2
