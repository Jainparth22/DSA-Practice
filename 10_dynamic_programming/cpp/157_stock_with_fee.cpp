// LC#714 — Best Time to Buy/Sell with Fee
// Difficulty: Medium | Pattern: State Machine DP | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& p, int fee) {
    int cash = 0, hold = -p[0];
    for (int x : p) { cash = max(cash, hold + x - fee); hold = max(hold, cash - x); }
    return cash;
}
int main() { vector<int> p = {1,3,2,8,4,9}; cout << maxProfit(p, 2) << endl; } // 8
