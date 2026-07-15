// LC#1359 — Count All Valid Pickup and Delivery Options
// Difficulty: Hard | Pattern: Combinatorics | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int countOrders(int n) { const int M = 1e9 + 7; long long r = 1; for (int i = 1; i <= n; i++) r = r * (i * (2LL * i - 1) % M) % M; return r; }
int main() { cout << countOrders(1) << countOrders(2) << countOrders(3) << endl; } // 1690
