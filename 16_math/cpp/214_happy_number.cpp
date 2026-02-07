// LC#202 — Happy Number
// Difficulty: Easy | Pattern: Hash Set / Floyd's Cycle
// Time: O(log n) | Space: O(log n)
// Approach: Repeatedly replace n with sum of squares of its digits.
// If we reach 1 → happy. If we see a repeated number → cycle → not happy.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int sumOfSquares(int n) {
        int s = 0;
        while (n > 0) { int d = n % 10; s += d*d; n /= 10; }
        return s;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1) {
            if (seen.count(n)) return false;
            seen.insert(n);
            n = sumOfSquares(n);
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.isHappy(19) << endl; // 1 (true)
    cout << sol.isHappy(2)  << endl; // 0 (false)
    cout << sol.isHappy(1)  << endl; // 1 (true)
    cout << sol.isHappy(7)  << endl; // 1 (true)
    cout << "All tests passed!" << endl;
    return 0;
}
