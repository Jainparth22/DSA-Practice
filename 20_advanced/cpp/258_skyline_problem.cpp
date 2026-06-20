// LC#218 — The Skyline Problem
// Difficulty: Hard | Pattern: Sweep line + Max Heap | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> getSkyline(vector<vector<int>>& b) {
    vector<pair<int,int>> ev; for (auto& x : b) { ev.push_back({x[0], -x[2]}); ev.push_back({x[1], x[2]}); }
    sort(ev.begin(), ev.end()); multiset<int> h = {0}; vector<vector<int>> res; int prev = 0;
    for (auto& [x, hh] : ev) {
        if (hh < 0) h.insert(-hh); else h.erase(h.find(hh));
        int cur = *h.rbegin(); if (cur != prev) { res.push_back({x, cur}); prev = cur; }
    }
    return res;
}
int main() { vector<vector<int>> b = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}}; cout << getSkyline(b).size() << endl; } // 7
