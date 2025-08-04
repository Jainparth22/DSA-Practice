// LC#213 — House Robber II
// Difficulty: Medium | Pattern: DP (circular) | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int rob1(vector<int>& a, int l, int r) { int p = 0, c = 0; for (int i = l; i <= r; i++) { int t = max(c, p + a[i]); p = c; c = t; } return c; }
int rob(vector<int>& a) { int n = a.size(); if (n == 1) return a[0]; return max(rob1(a, 0, n - 2), rob1(a, 1, n - 1)); }
int main() { vector<int> a = {2,3,2}, b = {1,2,3,1}; cout << rob(a) << rob(b) << endl; } // 34
