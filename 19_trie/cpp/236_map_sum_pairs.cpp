// LC#677 — Map Sum Pairs
// Difficulty: Medium | Pattern: Trie with sums | Time: O(L) | Space: O(total chars)
#include <bits/stdc++.h>
using namespace std;
class MapSum {
    struct T { T* c[26] = {}; int sum = 0; }; T* root = new T(); unordered_map<string, int> kv;
public:
    void insert(string k, int v) {
        int delta = v - kv[k]; kv[k] = v; T* t = root;
        for (char c : k) { if (!t->c[c - 'a']) t->c[c - 'a'] = new T(); t = t->c[c - 'a']; t->sum += delta; }
    }
    int sum(string p) { T* t = root; for (char c : p) { if (!t->c[c - 'a']) return 0; t = t->c[c - 'a']; } return t->sum; }
};
int main() { MapSum m; m.insert("apple", 3); cout << m.sum("ap"); m.insert("app", 2); cout << m.sum("ap") << endl; } // 35
