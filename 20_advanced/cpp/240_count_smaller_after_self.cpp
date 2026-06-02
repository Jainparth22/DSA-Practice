// LC#315 — Count of Smaller Numbers After Self
// Difficulty: Hard | Pattern: Fenwick Tree (BIT) | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
vector<int> countSmaller(vector<int>& a) {
    vector<int> s = a; sort(s.begin(), s.end()); s.erase(unique(s.begin(), s.end()), s.end());
    int m = s.size(); vector<int> bit(m + 1), res(a.size());
    for (int i = a.size() - 1; i >= 0; i--) {
        int r = lower_bound(s.begin(), s.end(), a[i]) - s.begin();
        for (int k = r; k > 0; k -= k & -k) res[i] += bit[k];
        for (int k = r + 1; k <= m; k += k & -k) bit[k]++;
    }
    return res;
}
int main() { vector<int> a = {5,2,6,1}; for (int x : countSmaller(a)) cout << x << " "; } // 2 1 1 0
