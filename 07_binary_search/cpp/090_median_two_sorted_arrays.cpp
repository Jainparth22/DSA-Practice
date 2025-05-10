// LC#4 — Median of Two Sorted Arrays
// Difficulty: Hard | Pattern: Binary Search on partition | Time: O(log min(m,n)) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if (a.size() > b.size()) return findMedianSortedArrays(b, a);
    int m = a.size(), n = b.size(), l = 0, r = m, half = (m + n + 1) / 2;
    while (l <= r) {
        int i = (l + r) / 2, j = half - i;
        int aL = i ? a[i-1] : INT_MIN, aR = i < m ? a[i] : INT_MAX;
        int bL = j ? b[j-1] : INT_MIN, bR = j < n ? b[j] : INT_MAX;
        if (aL <= bR && bL <= aR) {
            if ((m + n) % 2) return max(aL, bL);
            return (max(aL, bL) + min(aR, bR)) / 2.0;
        }
        aL > bR ? r = i - 1 : l = i + 1;
    }
    return 0;
}
int main() { vector<int> a = {1,2}, b = {3,4}; cout << findMedianSortedArrays(a, b) << endl; } // 2.5
