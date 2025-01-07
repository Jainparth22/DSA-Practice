// LC#88 — Merge Sorted Array
// Difficulty: Easy | Pattern: Two Pointers (from end) | Time: O(m+n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& a, int m, vector<int>& b, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) a[k--] = (i >= 0 && a[i] > b[j]) ? a[i--] : b[j--];
}
int main() { vector<int> a = {1,2,3,0,0,0}, b = {2,5,6}; merge(a, 3, b, 3); for (int x : a) cout << x << " "; } // 1 2 2 3 5 6
