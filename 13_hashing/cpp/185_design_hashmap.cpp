// LC#706 — Design HashMap
// Difficulty: Easy | Pattern: Chaining buckets | Time: O(1) avg | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class MyHashMap {
    static const int B = 1009; vector<list<pair<int,int>>> t;
public:
    MyHashMap() : t(B) {}
    void put(int k, int v) { for (auto& p : t[k % B]) if (p.first == k) { p.second = v; return; } t[k % B].push_back({k, v}); }
    int get(int k) { for (auto& p : t[k % B]) if (p.first == k) return p.second; return -1; }
    void remove(int k) { t[k % B].remove_if([k](auto& p) { return p.first == k; }); }
};
int main() { MyHashMap m; m.put(1, 1); m.put(1, 2); cout << m.get(1) << m.get(3); m.remove(1); cout << m.get(1) << endl; } // 2-1-1
