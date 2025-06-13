// LC#105 — Construct Binary Tree from Preorder and Inorder
// Difficulty: Medium | Pattern: Divide & Conquer + Map | Time: O(n) | Space: O(n)
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
unordered_map<int,int> pos; int pi = 0;
TreeNode* go(vector<int>& pre, int l, int r) {
    if (l > r) return nullptr;
    TreeNode* n = new TreeNode(pre[pi++]); int m = pos[n->val];
    n->left = go(pre, l, m - 1); n->right = go(pre, m + 1, r);
    return n;
}
TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    for (int i = 0; i < (int)in.size(); i++) pos[in[i]] = i;
    return go(pre, 0, in.size() - 1);
}
int main() { vector<int> p = {3,9,20,15,7}, i = {9,3,15,20,7}; auto* t = buildTree(p, i); cout << t->val << t->left->val << t->right->val << endl; } // 3920
