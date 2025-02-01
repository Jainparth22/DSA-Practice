/*
 * LC #121 — Best Time to Buy and Sell Stock
 * Difficulty : Easy
 * Pattern    : Greedy / One-pass
 * Time       : O(n)
 * Space      : O(1)
 *
 * Approach:
 *   Track the minimum price seen so far (minPrice). At each day compute
 *   profit = prices[i] - minPrice. Update maxProfit if this profit is better.
 *   Update minPrice if prices[i] < minPrice.
 *   We never sell before we buy because minPrice is always a past day.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else {
                maxProfit = max(maxProfit, price - minPrice);
            }
        }
        return maxProfit;
    }
};

int main() {
    Solution sol;

    vector<int> p1 = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(p1) << "\n"; // 5  (buy at 1, sell at 6)

    vector<int> p2 = {7, 6, 4, 3, 1};
    cout << sol.maxProfit(p2) << "\n"; // 0  (prices only fall)

    vector<int> p3 = {2, 4, 1};
    cout << sol.maxProfit(p3) << "\n"; // 2  (buy at 2, sell at 4)

    return 0;
}
