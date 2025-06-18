// LC#116 — Populating Next Right Pointers
// Difficulty: Medium | Pattern: Level pointers (perfect tree) | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct Node { int val; Node *left, *right, *next; Node(int v) : val(v), left(0), right(0), next(0) {} };
Node* connect(Node* root) {
    for (Node* lvl = root; lvl && lvl->left; lvl = lvl->left)
        for (Node* c = lvl; c; c = c->next) { c->left->next = c->right; if (c->next) c->right->next = c->next->left; }
    return root;
}
int main() { Node a(1), b(2), c(3); a.left = &b; a.right = &c; connect(&a); cout << (b.next == &c) << (c.next == nullptr) << endl; } // 11
