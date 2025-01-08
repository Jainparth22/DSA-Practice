// LC#283 — Move Zeroes
// Difficulty: Easy | Pattern: Two Pointers | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& a) {
    int k = 0;
    for (int i = 0; i < (int)a.size(); i++) if (a[i]) swap(a[k++], a[i]);
}
int main() { vector<int> a = {0,1,0,3,12}; moveZeroes(a); for (int x : a) cout << x << " "; } // 1 3 12 0 0
