// LC#169 — Majority Element
// Difficulty: Easy | Pattern: Boyer-Moore Voting | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& a) {
    int cand = 0, cnt = 0;
    for (int x : a) { if (!cnt) cand = x; cnt += (x == cand) ? 1 : -1; }
    return cand;
}
int main() { vector<int> a = {2,2,1,1,1,2,2}; cout << majorityElement(a) << endl; } // 2
