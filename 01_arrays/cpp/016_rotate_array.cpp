// LC#189 — Rotate Array
// Difficulty: Medium | Pattern: Reversal | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int>& a, int k) {
    k %= a.size();
    reverse(a.begin(), a.end()); reverse(a.begin(), a.begin() + k); reverse(a.begin() + k, a.end());
}
int main() { vector<int> a = {1,2,3,4,5,6,7}; rotate(a, 3); for (int x : a) cout << x << " "; } // 5 6 7 1 2 3 4
