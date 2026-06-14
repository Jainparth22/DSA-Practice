// LC#1838 — Frequency of the Most Frequent Element
// Difficulty: Medium | Pattern: Sort + Sliding Window | Time: O(n log n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int maxFrequency(vector<int>& a, int k) {
    sort(a.begin(), a.end()); long long sum = 0; int l = 0, best = 0;
    for (int r = 0; r < (int)a.size(); r++) { sum += a[r]; while ((long long)a[r] * (r - l + 1) - sum > k) sum -= a[l++]; best = max(best, r - l + 1); }
    return best;
}
int main() { vector<int> a = {1,2,4}; cout << maxFrequency(a, 5) << endl; } // 3
