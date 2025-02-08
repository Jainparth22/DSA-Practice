// LC#904 — Fruit Into Baskets
// Difficulty: Medium | Pattern: Sliding Window + Map | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int totalFruit(vector<int>& f) {
    unordered_map<int,int> cnt; int l = 0, best = 0;
    for (int r = 0; r < (int)f.size(); r++) {
        cnt[f[r]]++;
        while (cnt.size() > 2) { if (--cnt[f[l]] == 0) cnt.erase(f[l]); l++; }
        best = max(best, r - l + 1);
    }
    return best;
}
int main() { vector<int> f = {1,2,3,2,2}; cout << totalFruit(f) << endl; } // 4
