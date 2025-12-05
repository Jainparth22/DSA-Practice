// LC#846 — Hand of Straights
// Difficulty: Medium | Pattern: Greedy + Ordered Map | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
bool isNStraightHand(vector<int>& h, int g) {
    if (h.size() % g) return false;
    map<int,int> c; for (int x : h) c[x]++;
    for (auto& [k, v] : c) if (v > 0) for (int i = 1; i < g; i++) { c[k + i] -= v; if (c[k + i] < 0) return false; }
    return true;
}
int main() { vector<int> h = {1,2,3,6,2,3,4,7,8}; cout << isNStraightHand(h, 3) << endl; } // 1
