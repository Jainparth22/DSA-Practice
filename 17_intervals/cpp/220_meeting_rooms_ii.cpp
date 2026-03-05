// LC#253 — Meeting Rooms II
// Difficulty: Medium | Pattern: Min Heap of end times | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int minMeetingRooms(vector<vector<int>>& v) {
    sort(v.begin(), v.end()); priority_queue<int, vector<int>, greater<int>> pq;
    for (auto& x : v) { if (!pq.empty() && pq.top() <= x[0]) pq.pop(); pq.push(x[1]); }
    return pq.size();
}
int main() { vector<vector<int>> v = {{0,30},{5,10},{15,20}}; cout << minMeetingRooms(v) << endl; } // 2
