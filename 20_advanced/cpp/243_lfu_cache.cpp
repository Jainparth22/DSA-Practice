// LC#460 — LFU Cache
// Difficulty: Hard | Pattern: Hash Maps + Frequency Buckets | Time: O(1) per op | Space: O(capacity)
#include <bits/stdc++.h>
using namespace std;
class LFUCache {
    int cap, minf = 0; unordered_map<int, pair<int,int>> kv;  // key -> (value, freq)
    unordered_map<int, list<int>> fl; unordered_map<int, list<int>::iterator> pos;
    void touch(int k) {
        int f = kv[k].second++; fl[f].erase(pos[k]); if (fl[f].empty() && minf == f) minf++;
        fl[f + 1].push_back(k); pos[k] = prev(fl[f + 1].end());
    }
public:
    LFUCache(int c) : cap(c) {}
    int get(int k) { if (!kv.count(k)) return -1; touch(k); return kv[k].first; }
    void put(int k, int v) {
        if (!cap) return;
        if (kv.count(k)) { kv[k].first = v; touch(k); return; }
        if ((int)kv.size() == cap) { int ev = fl[minf].front(); fl[minf].pop_front(); kv.erase(ev); pos.erase(ev); }
        kv[k] = {v, 1}; minf = 1; fl[1].push_back(k); pos[k] = prev(fl[1].end());
    }
};
int main() { LFUCache c(2); c.put(1, 1); c.put(2, 2); c.get(1); c.put(3, 3); cout << c.get(2) << c.get(3) << endl; } // -13
