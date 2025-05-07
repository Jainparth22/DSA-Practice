// LC#162 — Find Peak Element
// Difficulty: Medium | Pattern: Binary Search on slope | Time: O(log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int>& a) {
    int l = 0, r = a.size() - 1;
    while (l < r) { int m = l + (r - l) / 2; a[m] < a[m+1] ? l = m + 1 : r = m; }
    return l;
}
int main() { vector<int> a = {1,2,1,3,5,6,4}; cout << findPeakElement(a) << endl; } // 5
