// LC#327 — Count of Range Sum
// Difficulty: Hard | Pattern: Merge Sort on prefix sums | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int go(vector<long long>& p, int l, int r, int lo, int up) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2, cnt = go(p, l, m, lo, up) + go(p, m, r, lo, up), a = m, b = m;
    for (int i = l; i < m; i++) { while (a < r && p[a] - p[i] < lo) a++; while (b < r && p[b] - p[i] <= up) b++; cnt += b - a; }
    inplace_merge(p.begin() + l, p.begin() + m, p.begin() + r);
    return cnt;
}
int countRangeSum(vector<int>& a, int lo, int up) { vector<long long> p(a.size() + 1); for (size_t i = 0; i < a.size(); i++) p[i+1] = p[i] + a[i]; return go(p, 0, p.size(), lo, up); }
int main() { vector<int> a = {-2,5,-1}; cout << countRangeSum(a, -2, 2) << endl; } // 3
