// LC#410 — Split Array Largest Sum
// Difficulty: Hard | Pattern: Binary Search on answer | Time: O(n log S) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int splitArray(vector<int>& a, int k) {
    long long lo = *max_element(a.begin(), a.end()), hi = accumulate(a.begin(), a.end(), 0LL);
    while (lo < hi) {
        long long m = (lo + hi) / 2, cnt = 1, cur = 0;
        for (int x : a) { if (cur + x > m) { cnt++; cur = 0; } cur += x; }
        cnt <= k ? hi = m : lo = m + 1;
    }
    return lo;
}
int main() { vector<int> a = {7,2,5,10,8}; cout << splitArray(a, 2) << endl; } // 18
