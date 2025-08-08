/*
 * LC #322 — Coin Change
 * Difficulty : Medium
 * Pattern    : Dynamic Programming — Unbounded Knapsack
 * Time       : O(amount × coins)
 * Space      : O(amount)
 *
 * Recurrence:
 *   dp[i] = minimum coins to make amount i
 *   dp[0] = 0 (zero coins to make amount 0)
 *   dp[i] = min(dp[i], dp[i - coin] + 1)  for each coin <= i
 *   dp[i] = INT_MAX means amount i is not achievable
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

int main() {
    Solution sol;
    vector<int> c1 = {1, 5, 10, 25}; cout << sol.coinChange(c1, 41) << "\n"; // 4 (25+10+5+1)
    vector<int> c2 = {1, 5, 11};     cout << sol.coinChange(c2, 15) << "\n"; // 3 (5+5+5)
    vector<int> c3 = {2};            cout << sol.coinChange(c3, 3)  << "\n"; // -1
    vector<int> c4 = {1};            cout << sol.coinChange(c4, 0)  << "\n"; // 0
    vector<int> c5 = {1,2,5};        cout << sol.coinChange(c5, 11) << "\n"; // 3 (5+5+1)
    return 0;
}
