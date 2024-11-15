// LC#135 — Candy
// Difficulty: Hard | Pattern: Greedy (two pass) | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int candy(vector<int>& r) {
    int n = r.size(); vector<int> c(n, 1);
    for (int i = 1; i < n; i++) if (r[i] > r[i-1]) c[i] = c[i-1] + 1;
    for (int i = n - 2; i >= 0; i--) if (r[i] > r[i+1]) c[i] = max(c[i], c[i+1] + 1);
    return accumulate(c.begin(), c.end(), 0);
}
int main() { vector<int> r = {1,0,2}; cout << candy(r) << endl; } // 5
