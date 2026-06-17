// LC#373 — Find K Pairs with Smallest Sums
// Difficulty: Medium | Pattern: Min Heap | Time: O(k log k) | Space: O(k)
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
    vector<vector<int>> res; if (a.empty() || b.empty()) return res;
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
    for (int i = 0; i < min((int)a.size(), k); i++) pq.push({a[i] + b[0], i, 0});
    while (k-- && !pq.empty()) { auto [s, i, j] = pq.top(); pq.pop(); res.push_back({a[i], b[j]}); if (j + 1 < (int)b.size()) pq.push({a[i] + b[j+1], i, j + 1}); }
    return res;
}
int main() { vector<int> a = {1,7,11}, b = {2,4,6}; auto r = kSmallestPairs(a, b, 3); cout << r.size() << r[2][0] << r[2][1] << endl; } // 316
