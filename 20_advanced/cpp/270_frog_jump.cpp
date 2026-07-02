// LC#403 — Frog Jump
// Difficulty: Hard | Pattern: DP with sets of jump sizes | Time: O(n^2) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
bool canCross(vector<int>& s) {
    unordered_map<int, unordered_set<int>> m; for (int x : s) m[x]; m[0].insert(0);
    for (int x : s) for (int k : m[x]) for (int d = k - 1; d <= k + 1; d++) if (d > 0 && m.count(x + d)) m[x + d].insert(d);
    return !m[s.back()].empty();
}
int main() { vector<int> a = {0,1,3,5,6,8,12,17}, b = {0,1,2,3,4,8,9,11}; cout << canCross(a) << canCross(b) << endl; } // 10
