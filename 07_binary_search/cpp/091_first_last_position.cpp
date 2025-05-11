// LC#34 — Find First and Last Position
// Difficulty: Medium | Pattern: Lower/Upper Bound | Time: O(log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& a, int t) {
    auto lo = lower_bound(a.begin(), a.end(), t), hi = upper_bound(a.begin(), a.end(), t);
    if (lo == hi) return {-1, -1};
    return {int(lo - a.begin()), int(hi - a.begin()) - 1};
}
int main() { vector<int> a = {5,7,7,8,8,10}; auto r = searchRange(a, 8); cout << r[0] << " " << r[1] << endl; } // 3 4
