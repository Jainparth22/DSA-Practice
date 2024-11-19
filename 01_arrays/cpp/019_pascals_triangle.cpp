// LC#118 — Pascal's Triangle
// Difficulty: Easy | Pattern: Simulation | Time: O(n^2) | Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int n) {
    vector<vector<int>> t;
    for (int i = 0; i < n; i++) {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++) row[j] = t[i-1][j-1] + t[i-1][j];
        t.push_back(row);
    }
    return t;
}
int main() { auto t = generate(5); for (int x : t[4]) cout << x << " "; } // 1 4 6 4 1
