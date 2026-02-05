// LC#172 — Factorial Trailing Zeroes
// Difficulty: Medium | Pattern: Count factors of 5 | Time: O(log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int trailingZeroes(int n) { int c = 0; while (n) { n /= 5; c += n; } return c; }
int main() { cout << trailingZeroes(5) << trailingZeroes(100) << endl; } // 524
