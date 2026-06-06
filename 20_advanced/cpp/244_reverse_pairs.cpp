// LC#493 — Reverse Pairs
// Difficulty: Hard | Pattern: Merge Sort count | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int sortCount(vector<int>& a, int l, int r) {
    if (r - l <= 1) return 0;
    int m = (l + r) / 2, cnt = sortCount(a, l, m) + sortCount(a, m, r);
    for (int i = l, j = m; i < m; i++) { while (j < r && (long long)a[i] > 2LL * a[j]) j++; cnt += j - m; }
    inplace_merge(a.begin() + l, a.begin() + m, a.begin() + r);
    return cnt;
}
int reversePairs(vector<int>& a) { return sortCount(a, 0, a.size()); }
int main() { vector<int> a = {1,3,2,3,1}; cout << reversePairs(a) << endl; } // 2
