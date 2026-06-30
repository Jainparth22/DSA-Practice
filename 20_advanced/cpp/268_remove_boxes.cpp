// LC#546 — Remove Boxes
// Difficulty: Hard | Pattern: 3D Interval DP (memo) | Time: O(n^4) | Space: O(n^3)
#include <bits/stdc++.h>
using namespace std;
int memo[100][100][100];
int go(vector<int>& b, int l, int r, int k) {
    if (l > r) return 0;
    int& res = memo[l][r][k]; if (res) return res;
    while (r > l && b[r] == b[r-1]) { r--; k++; }
    res = go(b, l, r - 1, 0) + (k + 1) * (k + 1);
    for (int i = l; i < r; i++) if (b[i] == b[r]) res = max(res, go(b, l, i, k + 1) + go(b, i + 1, r - 1, 0));
    return res;
}
int removeBoxes(vector<int>& b) { memset(memo, 0, sizeof memo); return go(b, 0, b.size() - 1, 0); }
int main() { vector<int> b = {1,3,2,2,2,3,4,3,1}; cout << removeBoxes(b) << endl; } // 23
