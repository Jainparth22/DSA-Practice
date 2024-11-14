// LC#134 — Gas Station
// Difficulty: Medium | Pattern: Greedy | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < (int)gas.size(); i++) {
        int d = gas[i] - cost[i]; total += d; tank += d;
        if (tank < 0) { start = i + 1; tank = 0; }
    }
    return total >= 0 ? start : -1;
}
int main() { vector<int> g = {1,2,3,4,5}, c = {3,4,5,1,2}; cout << canCompleteCircuit(g, c) << endl; } // 3
