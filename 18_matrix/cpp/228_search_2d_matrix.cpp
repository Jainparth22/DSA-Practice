// LC#74 — Search a 2D Matrix
// Difficulty: Medium | Pattern: Binary Search on flattened matrix | Time: O(log mn) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& m, int t) {
    int R = m.size(), C = m[0].size(), l = 0, r = R * C - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2, v = m[mid / C][mid % C];
        if (v == t) return true;
        v < t ? l = mid + 1 : r = mid - 1;
    }
    return false;
}
int main() { vector<vector<int>> m = {{1,3,5,7},{10,11,16,20},{23,30,34,60}}; cout << searchMatrix(m, 3) << searchMatrix(m, 13) << endl; } // 10
