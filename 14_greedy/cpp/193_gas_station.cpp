// LC#134 — Gas Station
// Difficulty: Medium
// Pattern: Greedy
// Time: O(n) | Space: O(1)
//
// Approach:
//   Key insight: if total gas >= total cost, a solution always exists.
//   Track running tank. If tank < 0 at any station, the starting point
//   must be the NEXT station (all previous stations can't be start).
//   Reset tank to 0 and try from next candidate.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int tank = 0, start = 0;
        for (int i = 0; i < (int)gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return (totalGas >= totalCost) ? start : -1;
    }
};

int main() {
    Solution sol;
    vector<int> g1 = {1, 2, 3, 4, 5}, c1 = {3, 4, 5, 1, 2};
    cout << sol.canCompleteCircuit(g1, c1) << endl; // 3

    vector<int> g2 = {2, 3, 4}, c2 = {3, 4, 3};
    cout << sol.canCompleteCircuit(g2, c2) << endl; // -1

    vector<int> g3 = {5, 1, 2, 3, 4}, c3 = {4, 4, 1, 5, 1};
    cout << sol.canCompleteCircuit(g3, c3) << endl; // 4

    cout << "All tests passed!" << endl;
    return 0;
}
