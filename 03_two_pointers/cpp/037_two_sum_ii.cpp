// LC#167 — Two Sum II
// Difficulty: Medium | Pattern: Two Pointers | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& a, int t) {
    int l = 0, r = a.size() - 1;
    while (l < r) { int s = a[l] + a[r]; if (s == t) return {l + 1, r + 1}; s < t ? l++ : r--; }
    return {};
}
int main() { vector<int> a = {2,7,11,15}; auto r = twoSum(a, 9); cout << r[0] << " " << r[1] << endl; } // 1 2
