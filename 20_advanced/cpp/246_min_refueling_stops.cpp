// LC#871 — Minimum Number of Refueling Stops
// Difficulty: Hard | Pattern: Greedy + Max Heap | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int minRefuelStops(int target, int fuel, vector<vector<int>>& st) {
    priority_queue<int> pq; int stops = 0, i = 0; long long reach = fuel;
    while (reach < target) {
        while (i < (int)st.size() && st[i][0] <= reach) pq.push(st[i++][1]);
        if (pq.empty()) return -1;
        reach += pq.top(); pq.pop(); stops++;
    }
    return stops;
}
int main() { vector<vector<int>> s = {{10,60},{20,30},{30,30},{60,40}}; cout << minRefuelStops(100, 10, s) << endl; } // 2
