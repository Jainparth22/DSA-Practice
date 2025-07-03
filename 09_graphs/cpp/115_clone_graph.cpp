// LC#133 — Clone Graph
// Difficulty: Medium | Pattern: DFS + Map | Time: O(V+E) | Space: O(V)
#include <bits/stdc++.h>
using namespace std;
struct Node { int val; vector<Node*> nb; Node(int v) : val(v) {} };
Node* cloneGraph(Node* n, unordered_map<Node*, Node*>& m) {
    if (!n) return nullptr;
    if (m.count(n)) return m[n];
    Node* c = m[n] = new Node(n->val);
    for (auto* x : n->nb) c->nb.push_back(cloneGraph(x, m));
    return c;
}
int main() { Node a(1), b(2); a.nb = {&b}; b.nb = {&a}; unordered_map<Node*, Node*> m; Node* c = cloneGraph(&a, m); cout << (c != &a) << c->nb[0]->nb[0]->val << endl; } // 11
