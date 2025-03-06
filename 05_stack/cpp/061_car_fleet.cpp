// LC#853 — Car Fleet
// Difficulty: Medium | Pattern: Sort + Stack | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int carFleet(int target, vector<int>& pos, vector<int>& speed) {
    vector<pair<int,double>> c;
    for (size_t i = 0; i < pos.size(); i++) c.push_back({pos[i], (double)(target - pos[i]) / speed[i]});
    sort(c.rbegin(), c.rend());
    int fleets = 0; double cur = 0;
    for (auto& [p, t] : c) if (t > cur) { fleets++; cur = t; }
    return fleets;
}
int main() { vector<int> p = {10,8,0,5,3}, s = {2,4,1,1,3}; cout << carFleet(12, p, s) << endl; } // 3
