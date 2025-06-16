// LC#112 — Path Sum
// Difficulty: Easy | Pattern: DFS | Time: O(n) | Space: O(h)
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
bool hasPathSum(TreeNode* t, int s) {
    if (!t) return false;
    if (!t->left && !t->right) return t->val == s;
    return hasPathSum(t->left, s - t->val) || hasPathSum(t->right, s - t->val);
}
int main() { cout << hasPathSum(build({5,4,8,11,N,13,4,7,2,N,N,N,1}), 22) << endl; } // 1
