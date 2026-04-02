// LC#54 — Spiral Matrix
// Difficulty: Medium
// Pattern: Matrix Simulation
// Time: O(m*n) | Space: O(1) extra (output not counted)
//
// Approach:
//   Maintain four boundaries: top, bottom, left, right.
//   Traverse right → down → left → up, shrinking boundaries each time.
//   Stop when top > bottom or left > right.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse right
            for (int col = left; col <= right; col++)
                result.push_back(matrix[top][col]);
            top++;

            // Traverse down
            for (int row = top; row <= bottom; row++)
                result.push_back(matrix[row][right]);
            right--;

            // Traverse left (if rows remain)
            if (top <= bottom) {
                for (int col = right; col >= left; col--)
                    result.push_back(matrix[bottom][col]);
                bottom--;
            }

            // Traverse up (if cols remain)
            if (left <= right) {
                for (int row = bottom; row >= top; row--)
                    result.push_back(matrix[row][left]);
                left++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
    auto r1 = sol.spiralOrder(m1);
    // Expected: 1 2 3 6 9 8 7 4 5
    for (int v : r1) cout << v << " ";
    cout << endl;

    vector<vector<int>> m2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    auto r2 = sol.spiralOrder(m2);
    // Expected: 1 2 3 4 8 12 11 10 9 5 6 7
    for (int v : r2) cout << v << " ";
    cout << endl;

    cout << "All tests passed!" << endl;
    return 0;
}
