// LC#129 — Sum Root to Leaf Numbers
// Difficulty: Medium | Pattern: DFS | Time: O(n) | Space: O(h)
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
int sumNumbers(TreeNode* t, int cur = 0) {
    if (!t) return 0;
    cur = cur * 10 + t->val;
    if (!t->left && !t->right) return cur;
    return sumNumbers(t->left, cur) + sumNumbers(t->right, cur);
}
int main() { cout << sumNumbers(build({4,9,0,5,1})) << endl; } // 1026
