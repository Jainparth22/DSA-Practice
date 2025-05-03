/*
 * LC #875 — Koko Eating Bananas
 * Difficulty : Medium
 * Pattern    : Binary Search on Answer
 * Time       : O(n log m) where m = max(piles)
 * Space      : O(1)
 *
 * Approach:
 *   Search for the MINIMUM speed k such that Koko can finish all piles in h hours.
 *   feasible(k) = "can eat all piles at speed k within h hours"
 *   = sum( ceil(pile/k) ) <= h
 *   feasible is monotone: once true for k, also true for k+1.
 *   Binary search on answer in [1, max(piles)].
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canFinish(piles, mid, h)) hi = mid; // mid works, try smaller
            else lo = mid + 1;                        // too slow, go higher
        }
        return lo;
    }
private:
    bool canFinish(vector<int>& piles, int speed, int h) {
        long long hours = 0;
        for (int p : piles) hours += (p + speed - 1) / speed; // ceil(p/speed)
        return hours <= h;
    }
};

int main() {
    Solution sol;
    vector<int> p1 = {3, 6, 7, 11}; cout << sol.minEatingSpeed(p1, 8)  << "\n"; // 4
    vector<int> p2 = {30,11,23,4,20}; cout << sol.minEatingSpeed(p2,5) << "\n"; // 30
    vector<int> p3 = {30,11,23,4,20}; cout << sol.minEatingSpeed(p3,6) << "\n"; // 23
    return 0;
}
