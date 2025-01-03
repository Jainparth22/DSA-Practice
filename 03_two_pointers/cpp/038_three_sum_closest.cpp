// LC#16 — 3Sum Closest
// Difficulty: Medium | Pattern: Sort + Two Pointers | Time: O(n^2) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int threeSumClosest(vector<int>& a, int t) {
    sort(a.begin(), a.end()); int best = a[0] + a[1] + a[2];
    for (int i = 0; i < (int)a.size() - 2; i++) {
        int l = i + 1, r = a.size() - 1;
        while (l < r) {
            int s = a[i] + a[l] + a[r];
            if (abs(s - t) < abs(best - t)) best = s;
            if (s == t) return t; s < t ? l++ : r--;
        }
    }
    return best;
}
int main() { vector<int> a = {-1,2,1,-4}; cout << threeSumClosest(a, 1) << endl; } // 2
