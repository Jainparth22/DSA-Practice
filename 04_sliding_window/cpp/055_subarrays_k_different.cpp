// LC#992 — Subarrays with K Different Integers
// Difficulty: Hard | Pattern: atMost(K) - atMost(K-1) | Time: O(n) | Space: O(k)
#include <bits/stdc++.h>
using namespace std;
int atMost(vector<int>& a, int k) {
    unordered_map<int,int> cnt; int l = 0, res = 0;
    for (int r = 0; r < (int)a.size(); r++) {
        cnt[a[r]]++;
        while ((int)cnt.size() > k) { if (--cnt[a[l]] == 0) cnt.erase(a[l]); l++; }
        res += r - l + 1;
    }
    return res;
}
int subarraysWithKDistinct(vector<int>& a, int k) { return atMost(a, k) - atMost(a, k - 1); }
int main() { vector<int> a = {1,2,1,2,3}; cout << subarraysWithKDistinct(a, 2) << endl; } // 7
