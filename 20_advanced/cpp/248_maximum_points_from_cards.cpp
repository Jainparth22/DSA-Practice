// LC#1423 — Maximum Points You Can Obtain from Cards
// Difficulty: Medium | Pattern: Sliding window on complement | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int maxScore(vector<int>& c, int k) {
    int n = c.size(), sum = accumulate(c.begin(), c.begin() + k, 0), best = sum;
    for (int i = 1; i <= k; i++) { sum += c[n - i] - c[k - i]; best = max(best, sum); }
    return best;
}
int main() { vector<int> c = {1,2,3,4,5,6,1}; cout << maxScore(c, 3) << endl; } // 12
