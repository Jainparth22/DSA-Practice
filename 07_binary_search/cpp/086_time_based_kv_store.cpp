// LC#981 — Time Based Key-Value Store
// Difficulty: Medium | Pattern: Binary Search on timestamps | Time: O(log n) get | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
class TimeMap {
    unordered_map<string, vector<pair<int,string>>> m;
public:
    void set(string k, string v, int t) { m[k].push_back({t, v}); }
    string get(string k, int t) {
        auto& v = m[k];
        auto it = upper_bound(v.begin(), v.end(), make_pair(t, string(1, '\x7f')));
        return it == v.begin() ? "" : prev(it)->second;
    }
};
int main() { TimeMap tm; tm.set("foo", "bar", 1); cout << tm.get("foo", 1) << tm.get("foo", 3) << "[" << tm.get("foo", 0) << "]" << endl; } // barbar[]
