// LC#572 — Subtree of Another Tree
// Difficulty: Easy | Pattern: DFS + Same Tree | Time: O(mn) | Space: O(h)
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
bool same(TreeNode* a, TreeNode* b) { if (!a || !b) return a == b; return a->val == b->val && same(a->left, b->left) && same(a->right, b->right); }
bool isSubtree(TreeNode* r, TreeNode* s) { if (!r) return !s; return same(r, s) || isSubtree(r->left, s) || isSubtree(r->right, s); }
int main() { cout << isSubtree(build({3,4,5,1,2}), build({4,1,2})) << endl; } // 1
