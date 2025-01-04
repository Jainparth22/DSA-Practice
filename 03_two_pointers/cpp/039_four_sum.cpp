// LC#18 — 4Sum
// Difficulty: Medium | Pattern: Sort + Two Pointers | Time: O(n^3) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int>& a, int t) {
    sort(a.begin(), a.end()); int n = a.size(); vector<vector<int>> res;
    for (int i = 0; i < n - 3; i++) {
        if (i && a[i] == a[i-1]) continue;
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && a[j] == a[j-1]) continue;
            int l = j + 1, r = n - 1;
            while (l < r) {
                long long s = (long long)a[i] + a[j] + a[l] + a[r];
                if (s == t) { res.push_back({a[i], a[j], a[l], a[r]}); l++; r--; while (l < r && a[l] == a[l-1]) l++; }
                else if (s < t) l++; else r--;
            }
        }
    }
    return res;
}
int main() { vector<int> a = {1,0,-1,0,-2,2}; cout << fourSum(a, 0).size() << endl; } // 3
