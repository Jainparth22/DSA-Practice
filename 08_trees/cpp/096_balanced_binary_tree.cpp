// LC#110 — Balanced Binary Tree
// Difficulty: Easy | Pattern: DFS height | Time: O(n) | Space: O(h)
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
int h(TreeNode* t) { if (!t) return 0; int l = h(t->left), r = h(t->right); return (l < 0 || r < 0 || abs(l - r) > 1) ? -1 : 1 + max(l, r); }
bool isBalanced(TreeNode* t) { return h(t) >= 0; }
int main() { cout << isBalanced(build({3,9,20,N,N,15,7})) << isBalanced(build({1,2,2,3,3,N,N,4,4})) << endl; } // 10
