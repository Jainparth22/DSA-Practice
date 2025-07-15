// LC#787 — Cheapest Flights Within K Stops
// Difficulty: Medium | Pattern: Bellman-Ford (k+1 rounds) | Time: O(k*E) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
    vector<int> d(n, INT_MAX); d[src] = 0;
    for (int i = 0; i <= k; i++) {
        auto t = d;
        for (auto& e : f) if (d[e[0]] != INT_MAX && d[e[0]] + e[2] < t[e[1]]) t[e[1]] = d[e[0]] + e[2];
        d = t;
    }
    return d[dst] == INT_MAX ? -1 : d[dst];
}
int main() { vector<vector<int>> f = {{0,1,100},{1,2,100},{0,2,500}}; cout << findCheapestPrice(3, f, 0, 2, 1) << endl; } // 200
