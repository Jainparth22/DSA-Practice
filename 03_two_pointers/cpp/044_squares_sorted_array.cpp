// LC#977 — Squares of a Sorted Array
// Difficulty: Easy | Pattern: Two Pointers | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
vector<int> sortedSquares(vector<int>& a) {
    int n = a.size(), l = 0, r = n - 1; vector<int> res(n);
    for (int k = n - 1; k >= 0; k--) {
        if (abs(a[l]) > abs(a[r])) { res[k] = a[l] * a[l]; l++; } else { res[k] = a[r] * a[r]; r--; }
    }
    return res;
}
int main() { vector<int> a = {-4,-1,0,3,10}; for (int x : sortedSquares(a)) cout << x << " "; } // 0 1 9 16 100
