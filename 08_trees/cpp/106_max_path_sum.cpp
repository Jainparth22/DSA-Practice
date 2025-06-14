// LC#124 — Binary Tree Maximum Path Sum
// Difficulty: Hard | Pattern: DFS gain | Time: O(n) | Space: O(h)
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
int best;
int gain(TreeNode* t) {
    if (!t) return 0;
    int l = max(0, gain(t->left)), r = max(0, gain(t->right));
    best = max(best, t->val + l + r);
    return t->val + max(l, r);
}
int maxPathSum(TreeNode* t) { best = INT_MIN; gain(t); return best; }
int main() { cout << maxPathSum(build({-10,9,20,N,N,15,7})) << endl; } // 42
