// LC#978 — Longest Turbulent Subarray
// Difficulty: Medium | Pattern: DP on comparisons | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int maxTurbulenceSize(vector<int>& a) {
    int up = 1, down = 1, best = 1;
    for (size_t i = 1; i < a.size(); i++) {
        if (a[i] > a[i-1]) { up = down + 1; down = 1; }
        else if (a[i] < a[i-1]) { down = up + 1; up = 1; }
        else up = down = 1;
        best = max({best, up, down});
    }
    return best;
}
int main() { vector<int> a = {9,4,2,10,7,8,8,1,9}; cout << maxTurbulenceSize(a) << endl; } // 5
