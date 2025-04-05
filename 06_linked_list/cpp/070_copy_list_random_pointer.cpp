// LC#138 — Copy List with Random Pointer
// Difficulty: Medium | Pattern: Hash Map | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
struct Node { int val; Node *next, *random; Node(int v) : val(v), next(nullptr), random(nullptr) {} };
Node* copyRandomList(Node* h) {
    unordered_map<Node*, Node*> m;
    for (Node* c = h; c; c = c->next) m[c] = new Node(c->val);
    for (Node* c = h; c; c = c->next) { m[c]->next = c->next ? m[c->next] : nullptr; m[c]->random = c->random ? m[c->random] : nullptr; }
    return h ? m[h] : nullptr;
}
int main() { Node a(1), b(2); a.next = &b; a.random = &b; b.random = &b; Node* c = copyRandomList(&a); cout << (c != &a) << c->random->val << endl; } // 12
