// LC#1493 — Longest Subarray of 1s After Deleting One Element
// Difficulty: Medium | Pattern: Sliding Window | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int>& a) {
    int l = 0, zeros = 0, best = 0;
    for (int r = 0; r < (int)a.size(); r++) { zeros += a[r] == 0; while (zeros > 1) zeros -= a[l++] == 0; best = max(best, r - l); }
    return best;
}
int main() { vector<int> a = {1,1,0,1}; cout << longestSubarray(a) << endl; } // 3
