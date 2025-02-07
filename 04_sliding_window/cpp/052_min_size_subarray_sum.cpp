// LC#209 — Minimum Size Subarray Sum
// Difficulty: Medium | Pattern: Variable Sliding Window | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int t, vector<int>& a) {
    int l = 0, sum = 0, best = INT_MAX;
    for (int r = 0; r < (int)a.size(); r++) {
        sum += a[r];
        while (sum >= t) { best = min(best, r - l + 1); sum -= a[l++]; }
    }
    return best == INT_MAX ? 0 : best;
}
int main() { vector<int> a = {2,3,1,2,4,3}; cout << minSubArrayLen(7, a) << endl; } // 2
