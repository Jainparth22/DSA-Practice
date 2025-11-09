// LC#454 — 4Sum II
// Difficulty: Medium | Pattern: Hash Map of pair sums | Time: O(n^2) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
    unordered_map<int,int> m; int res = 0;
    for (int x : a) for (int y : b) m[x + y]++;
    for (int x : c) for (int y : d) { auto it = m.find(-(x + y)); if (it != m.end()) res += it->second; }
    return res;
}
int main() { vector<int> a = {1,2}, b = {-2,-1}, c = {-1,2}, d = {0,2}; cout << fourSumCount(a, b, c, d) << endl; } // 2
