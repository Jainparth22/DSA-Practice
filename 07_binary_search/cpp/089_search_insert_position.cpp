// LC#35 — Search Insert Position
// Difficulty: Easy | Pattern: Lower Bound | Time: O(log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& a, int t) { return lower_bound(a.begin(), a.end(), t) - a.begin(); }
int main() { vector<int> a = {1,3,5,6}; cout << searchInsert(a, 5) << searchInsert(a, 2) << searchInsert(a, 7) << endl; } // 214
