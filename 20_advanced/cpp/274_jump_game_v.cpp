// LC#1340 — Jump Game V
// Difficulty: Hard | Pattern: Memoized DFS | Time: O(n * d) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int dfs(vector<int>& a, int d, int i, vector<int>& memo) {
    if (memo[i]) return memo[i]; int best = 1, n = a.size();
    for (int dir : {-1, 1}) for (int j = i + dir; j >= 0 && j < n && abs(j - i) <= d && a[j] < a[i]; j += dir) best = max(best, 1 + dfs(a, d, j, memo));
    return memo[i] = best;
}
int maxJumps(vector<int>& a, int d) { vector<int> memo(a.size()); int best = 0; for (int i = 0; i < (int)a.size(); i++) best = max(best, dfs(a, d, i, memo)); return best; }
int main() { vector<int> a = {6,4,14,6,8,13,9,7,10,6,12}; cout << maxJumps(a, 2) << endl; } // 4
