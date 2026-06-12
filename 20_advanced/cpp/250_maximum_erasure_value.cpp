// LC#1695 — Maximum Erasure Value
// Difficulty: Medium | Pattern: Sliding window + set | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int maximumUniqueSubarray(vector<int>& a) {
    unordered_set<int> seen; int l = 0, sum = 0, best = 0;
    for (int r = 0; r < (int)a.size(); r++) {
        while (seen.count(a[r])) { seen.erase(a[l]); sum -= a[l++]; }
        seen.insert(a[r]); sum += a[r]; best = max(best, sum);
    }
    return best;
}
int main() { vector<int> a = {4,2,4,5,6}; cout << maximumUniqueSubarray(a) << endl; } // 17
