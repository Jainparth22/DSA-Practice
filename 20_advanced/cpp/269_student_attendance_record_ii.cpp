// LC#552 — Student Attendance Record II
// Difficulty: Hard | Pattern: DP over (absences, late streak) | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int checkRecord(int n) {
    const int M = 1e9 + 7; long long dp[2][3] = {{1,0,0},{0,0,0}};
    while (n--) {
        long long nd[2][3] = {};
        for (int a = 0; a < 2; a++) for (int l = 0; l < 3; l++) {
            long long v = dp[a][l]; if (!v) continue;
            nd[a][0] = (nd[a][0] + v) % M;                          // P
            if (a == 0) nd[1][0] = (nd[1][0] + v) % M;              // A
            if (l < 2) nd[a][l + 1] = (nd[a][l + 1] + v) % M;       // L
        }
        memcpy(dp, nd, sizeof dp);
    }
    long long s = 0; for (auto& r : dp) for (long long v : r) s += v; return s % M;
}
int main() { cout << checkRecord(2) << " " << checkRecord(1) << endl; } // 8 3
