// LC#309 — Best Time to Buy/Sell with Cooldown
// Difficulty: Medium | Pattern: State Machine DP | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& p) {
    int hold = INT_MIN, sold = 0, rest = 0;
    for (int x : p) { int prevSold = sold; sold = hold + x; hold = max(hold, rest - x); rest = max(rest, prevSold); }
    return max(sold, rest);
}
int main() { vector<int> p = {1,2,3,0,2}; cout << maxProfit(p) << endl; } // 3
