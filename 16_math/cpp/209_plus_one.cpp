// LC#66 — Plus One
// Difficulty: Easy | Pattern: Carry propagation | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> d) {
    for (int i = d.size() - 1; i >= 0; i--) { if (++d[i] < 10) return d; d[i] = 0; }
    d.insert(d.begin(), 1); return d;
}
int main() { for (int x : plusOne({9,9})) cout << x; } // 100
