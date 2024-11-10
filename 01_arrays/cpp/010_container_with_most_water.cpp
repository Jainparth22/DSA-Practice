/*
 * LC #11 — Container With Most Water
 * Difficulty : Medium
 * Pattern    : Two Pointers (Greedy)
 * Time       : O(n)
 * Space      : O(1)
 *
 * Approach:
 *   Start with widest container (l=0, r=n-1).
 *   Area = min(height[l], height[r]) * (r - l)
 *   Move the pointer with the SHORTER height inward — only way to find
 *   a potentially larger area (shrinking width is unavoidable, so we
 *   must try to increase height).
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxWater = 0;
        while (l < r) {
            int water = min(height[l], height[r]) * (r - l);
            maxWater = max(maxWater, water);
            if (height[l] <= height[r]) l++;
            else r--;
        }
        return maxWater;
    }
};

int main() {
    Solution sol;

    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxArea(h1) << "\n"; // 49

    vector<int> h2 = {1, 1};
    cout << sol.maxArea(h2) << "\n"; // 1

    vector<int> h3 = {4, 3, 2, 1, 4};
    cout << sol.maxArea(h3) << "\n"; // 16

    return 0;
}
