// LC#1046 — Last Stone Weight
// Difficulty: Easy | Pattern: Max Heap | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int lastStoneWeight(vector<int>& s) {
    priority_queue<int> pq(s.begin(), s.end());
    while (pq.size() > 1) { int a = pq.top(); pq.pop(); int b = pq.top(); pq.pop(); if (a != b) pq.push(a - b); }
    return pq.empty() ? 0 : pq.top();
}
int main() { vector<int> s = {2,7,4,1,8,1}; cout << lastStoneWeight(s) << endl; } // 1
