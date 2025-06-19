// LC#114 — Flatten Binary Tree to Linked List
// Difficulty: Medium | Pattern: Morris-style | Time: O(n) | Space: O(1)
#include <bits/stdc++.h>
using namespace std;
struct TreeNode { int val; TreeNode *left = nullptr, *right = nullptr; TreeNode(int v) : val(v) {} };
const int N = INT_MIN;  // null marker
TreeNode* build(vector<int> v) {  // level-order
    if (v.empty() || v[0] == N) return nullptr;
    TreeNode* root = new TreeNode(v[0]); queue<TreeNode*> q; q.push(root);
    for (size_t i = 1; i < v.size(); ) {
        TreeNode* n = q.front(); q.pop();
        if (i < v.size() && v[i] != N) { n->left = new TreeNode(v[i]); q.push(n->left); } i++;
        if (i < v.size() && v[i] != N) { n->right = new TreeNode(v[i]); q.push(n->right); } i++;
    }
    return root;
}
void flatten(TreeNode* r) {
    while (r) {
        if (r->left) {
            TreeNode* p = r->left; while (p->right) p = p->right;
            p->right = r->right; r->right = r->left; r->left = nullptr;
        }
        r = r->right;
    }
}
int main() { auto* t = build({1,2,5,3,4,N,6}); flatten(t); for (; t; t = t->right) cout << t->val << " "; } // 1 2 3 4 5 6
