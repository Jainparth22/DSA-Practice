// LC#703 — Kth Largest Element in a Stream
// Difficulty: Easy | Pattern: Min Heap of size k | Time: O(log k) per add | Space: O(k)
#include <bits/stdc++.h>
using namespace std;
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq; int k;
public:
    KthLargest(int k, vector<int>& a) : k(k) { for (int x : a) add(x); }
    int add(int v) { pq.push(v); if ((int)pq.size() > k) pq.pop(); return pq.top(); }
};
int main() { vector<int> a = {4,5,8,2}; KthLargest kl(3, a); cout << kl.add(3) << kl.add(5) << kl.add(10) << endl; } // 455
