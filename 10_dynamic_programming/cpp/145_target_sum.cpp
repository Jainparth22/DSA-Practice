// LC#494 — Target Sum
// Difficulty: Medium | Pattern: Subset Sum DP | Time: O(n * S) | Space: O(S)
#include <bits/stdc++.h>
using namespace std;
int findTargetSumWays(vector<int>& a, int t) {
    int sum = accumulate(a.begin(), a.end(), 0);
    if (abs(t) > sum || (sum + t) % 2) return 0;
    int s = (sum + t) / 2; vector<int> dp(s + 1); dp[0] = 1;
    for (int x : a) for (int j = s; j >= x; j--) dp[j] += dp[j - x];
    return dp[s];
}
int main() { vector<int> a = {1,1,1,1,1}; cout << findTargetSumWays(a, 3) << endl; } // 5
