// LC#1326 — Minimum Number of Taps to Open to Water a Garden
// Difficulty: Hard | Pattern: Greedy (jump game) | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int minTaps(int n, vector<int>& r) {
    vector<int> far(n + 1); for (int i = 0; i <= n; i++) { int l = max(0, i - r[i]); far[l] = max(far[l], min(n, i + r[i])); }
    int taps = 0, end = 0, reach = 0;
    for (int i = 0; i <= n; i++) { if (i > reach) return -1; if (i > end) { taps++; end = reach; } reach = max(reach, far[i]); }
    return end >= n ? taps : (reach >= n ? taps + 1 : -1);
}
int main() { vector<int> r = {3,4,1,1,0,0}; cout << minTaps(5, r) << endl; } // 1
