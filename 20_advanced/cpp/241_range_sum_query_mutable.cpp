// LC#307 — Range Sum Query - Mutable
// Difficulty: Medium | Pattern: Fenwick Tree (BIT) | Time: O(log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class NumArray {
    vector<int> bit, a; int n;
    void add(int i, int d) { for (i++; i <= n; i += i & -i) bit[i] += d; }
    int pre(int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
public:
    NumArray(vector<int>& v) : bit(v.size() + 1), a(v.size()), n(v.size()) { for (int i = 0; i < n; i++) update(i, v[i]); }
    void update(int i, int v) { add(i, v - a[i]); a[i] = v; }
    int sumRange(int l, int r) { return pre(r + 1) - pre(l); }
};
int main() { vector<int> v = {1,3,5}; NumArray na(v); cout << na.sumRange(0, 2); na.update(1, 2); cout << na.sumRange(0, 2) << endl; } // 98
