// LC#69 — Sqrt(x)
// Difficulty: Easy | Pattern: Binary Search on answer | Time: O(log x) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int mySqrt(int x) {
    long long l = 0, r = x;
    while (l < r) { long long m = (l + r + 1) / 2; m * m <= x ? l = m : r = m - 1; }
    return l;
}
int main() { cout << mySqrt(8) << mySqrt(16) << endl; } // 24
