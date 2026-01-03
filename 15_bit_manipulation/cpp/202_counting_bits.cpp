// LC#338 — Counting Bits
// Difficulty: Easy | Pattern: DP on bits | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
vector<int> countBits(int n) { vector<int> r(n + 1); for (int i = 1; i <= n; i++) r[i] = r[i >> 1] + (i & 1); return r; }
int main() { for (int x : countBits(5)) cout << x << " "; } // 0 1 1 2 1 2
