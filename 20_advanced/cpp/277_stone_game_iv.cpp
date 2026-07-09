// LC#1510 — Stone Game IV
// Difficulty: Hard | Pattern: Game DP | Time: O(n sqrt n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1);
    for (int i = 1; i <= n; i++) for (int k = 1; k * k <= i && !dp[i]; k++) dp[i] = !dp[i - k * k];
    return dp[n];
}
int main() { cout << winnerSquareGame(1) << winnerSquareGame(2) << winnerSquareGame(4) << winnerSquareGame(7) << endl; } // 1010
