// LC#973 — K Closest Points to Origin
// Difficulty: Medium | Pattern: Max Heap of size k | Time: O(n log k) | Space: O(k)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < (int)p.size(); i++) { pq.push({p[i][0]*p[i][0] + p[i][1]*p[i][1], i}); if ((int)pq.size() > k) pq.pop(); }
    vector<vector<int>> res; while (!pq.empty()) { res.push_back(p[pq.top().second]); pq.pop(); }
    return res;
}
int main() { vector<vector<int>> p = {{1,3},{-2,2}}; cout << kClosest(p, 1)[0][0] << endl; } // -2
