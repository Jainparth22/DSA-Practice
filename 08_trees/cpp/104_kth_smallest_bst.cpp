// LC#230 — Kth Smallest Element in a BST
// Difficulty: Medium | Pattern: Iterative Inorder | Time: O(h + k) | Space: O(h)
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
int kthSmallest(TreeNode* r, int k) {
    stack<TreeNode*> st;
    while (r || !st.empty()) {
        while (r) { st.push(r); r = r->left; }
        r = st.top(); st.pop();
        if (--k == 0) return r->val;
        r = r->right;
    }
    return -1;
}
int main() { cout << kthSmallest(build({3,1,4,N,2}), 1) << endl; } // 1
