// LC#502 — IPO
// Difficulty: Hard | Pattern: Greedy + Two Heaps | Time: O(n log n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = profits.size(); vector<pair<int,int>> p; for (int i = 0; i < n; i++) p.push_back({capital[i], profits[i]});
    sort(p.begin(), p.end()); priority_queue<int> pq; int i = 0;
    while (k--) {
        while (i < n && p[i].first <= w) pq.push(p[i++].second);
        if (pq.empty()) break;
        w += pq.top(); pq.pop();
    }
    return w;
}
int main() { vector<int> pr = {1,2,3}, c = {0,1,1}; cout << findMaximizedCapital(2, 0, pr, c) << endl; } // 4
