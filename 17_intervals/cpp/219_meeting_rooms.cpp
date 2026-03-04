// LC#252 — Meeting Rooms
// Difficulty: Easy | Pattern: Sort + adjacent check | Time: O(n log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
bool canAttendMeetings(vector<vector<int>>& v) {
    sort(v.begin(), v.end());
    for (size_t i = 1; i < v.size(); i++) if (v[i][0] < v[i-1][1]) return false;
    return true;
}
int main() { vector<vector<int>> a = {{0,30},{5,10},{15,20}}, b = {{7,10},{2,4}}; cout << canAttendMeetings(a) << canAttendMeetings(b) << endl; } // 01
