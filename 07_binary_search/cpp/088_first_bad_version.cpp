// LC#278 — First Bad Version
// Difficulty: Easy | Pattern: Binary Search | Time: O(log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int BAD = 4;
bool isBadVersion(int v) { return v >= BAD; }
int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l < r) { int m = l + (r - l) / 2; isBadVersion(m) ? r = m : l = m + 1; }
    return l;
}
int main() { cout << firstBadVersion(5) << endl; } // 4
