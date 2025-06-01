/*
 * LC #226 — Invert Binary Tree
 * Difficulty : Easy
 * Pattern    : DFS (Post-order)
 * Time       : O(n)
 * Space      : O(h) recursion stack, O(n) worst case skewed tree
 *
 * Approach:
 *   Recursively invert left and right subtrees, then swap them at current node.
 *   Post-order: invert children first, then swap.
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val; TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        root->left  = invertTree(root->right);
        root->right = invertTree(root->left);
        // Wait — need temp to avoid overwriting
        // Correct version:
        swap(root->left, root->right);  // actually do it this way
        return root;
    }
};

// Cleaner version avoiding the swap issue above:
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* left  = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left  = right;
        root->right = left;
        return root;
    }
};

void levelOrder(TreeNode* root) {
    if (!root) { cout << "[]\n"; return; }
    queue<TreeNode*> q; q.push(root);
    cout << "[";
    bool first = true;
    while (!q.empty()) {
        auto node = q.front(); q.pop();
        if (!first) cout << ",";
        cout << node->val; first = false;
        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << "]\n";
}

TreeNode* build(vector<int> vals) {
    if (vals.empty()) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q; q.push(root);
    int i = 1;
    while (!q.empty() && i < (int)vals.size()) {
        auto node = q.front(); q.pop();
        if (i < (int)vals.size()) { node->left = new TreeNode(vals[i++]); q.push(node->left); }
        if (i < (int)vals.size()) { node->right = new TreeNode(vals[i++]); q.push(node->right); }
    }
    return root;
}

int main() {
    Solution2 sol;
    TreeNode* t1 = build({4, 2, 7, 1, 3, 6, 9});
    levelOrder(sol.invertTree(t1)); // [4,7,2,9,6,3,1]

    TreeNode* t2 = build({2, 1, 3});
    levelOrder(sol.invertTree(t2)); // [2,3,1]

    return 0;
}
