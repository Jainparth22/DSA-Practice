// LC#543 — Diameter of Binary Tree
// Difficulty: Easy
// Pattern: DFS / Tree Recursion
// Time: O(n) | Space: O(h) recursion stack
//
// Approach:
//   The diameter through any node = left_height + right_height.
//   For each node, compute height (max depth of subtree) recursively.
//   Update global max diameter during each height calculation.
//   Return height = 1 + max(left_height, right_height).

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int diameter = 0;
    int height(TreeNode* node) {
        if (!node) return 0;
        int left  = height(node->left);
        int right = height(node->right);
        diameter = max(diameter, left + right);
        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        height(root);
        return diameter;
    }
};

int main() {
    Solution sol;
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    TreeNode* root = new TreeNode(1);
    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left  = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << sol.diameterOfBinaryTree(root) << endl; // 3 (4->2->1->3 or 4->2->5)

    TreeNode* r2 = new TreeNode(1);
    r2->left = new TreeNode(2);
    cout << sol.diameterOfBinaryTree(r2) << endl; // 1

    cout << "All tests passed!" << endl;
    return 0;
}
