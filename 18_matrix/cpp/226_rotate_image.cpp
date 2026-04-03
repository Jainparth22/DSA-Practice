// LC#48 — Rotate Image
// Difficulty: Medium
// Pattern: Matrix In-Place Transformation
// Time: O(n^2) | Space: O(1)
//
// Approach:
//   Rotating 90° clockwise in-place = Transpose + Reverse each row.
//   Transpose: swap matrix[i][j] with matrix[j][i] for j > i.
//   Reverse rows: reverse each row individually.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Step 1: Transpose
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        // Step 2: Reverse each row
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

int main() {
    Solution sol;
    vector<vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(m1);
    // Expected: [[7,4,1],[8,5,2],[9,6,3]]
    for (auto& row : m1) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }

    vector<vector<int>> m2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate(m2);
    // Expected: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
    for (auto& row : m2) {
        for (int v : row) cout << v << " ";
        cout << endl;
    }

    cout << "All tests passed!" << endl;
    return 0;
}
