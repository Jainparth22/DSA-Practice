// LC#199 — Binary Tree Right Side View
// Difficulty: Medium | Pattern: BFS level order | Time: O(n) | Space: O(w)
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
vector<int> rightSideView(TreeNode* r) {
    vector<int> res; if (!r) return res; queue<TreeNode*> q; q.push(r);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) { auto* t = q.front(); q.pop(); if (i == n - 1) res.push_back(t->val); if (t->left) q.push(t->left); if (t->right) q.push(t->right); }
    }
    return res;
}
int main() { for (int x : rightSideView(build({1,2,3,N,5,N,4}))) cout << x << " "; } // 1 3 4
