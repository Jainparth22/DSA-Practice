// LC#42 — Trapping Rain Water
// Difficulty: Hard | Pattern: Two Pointers | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int trap(vector<int>& h) {
    int l = 0, r = h.size() - 1, lm = 0, rm = 0, res = 0;
    while (l < r) {
        if (h[l] < h[r]) { lm = max(lm, h[l]); res += lm - h[l]; l++; }
        else { rm = max(rm, h[r]); res += rm - h[r]; r--; }
    }
    return res;
}
int main() { vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1}; cout << trap(h) << endl; } // 6
