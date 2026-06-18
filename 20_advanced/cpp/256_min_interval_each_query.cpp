// LC#1851 — Minimum Interval to Include Each Query
// Difficulty: Hard | Pattern: Sort + Min Heap | Time: O((n+q) log n) | Space: O(n+q)
#include <bits/stdc++.h>
using namespace std;
vector<int> minInterval(vector<vector<int>>& iv, vector<int>& qs) {
    sort(iv.begin(), iv.end()); vector<int> idx(qs.size()); iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b) { return qs[a] < qs[b]; });
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; vector<int> res(qs.size(), -1); size_t i = 0;
    for (int q : idx) {
        while (i < iv.size() && iv[i][0] <= qs[q]) { pq.push({iv[i][1] - iv[i][0] + 1, iv[i][1]}); i++; }
        while (!pq.empty() && pq.top().second < qs[q]) pq.pop();
        if (!pq.empty()) res[q] = pq.top().first;
    }
    return res;
}
int main() { vector<vector<int>> iv = {{1,4},{2,4},{3,6},{4,4}}; vector<int> q = {2,3,4,5}; for (int x : minInterval(iv, q)) cout << x << " "; } // 3 3 1 4
