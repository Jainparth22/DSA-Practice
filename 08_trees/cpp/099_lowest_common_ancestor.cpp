// LC#235 — Lowest Common Ancestor of BST  (generalised as LC#236 for any BT)
// Difficulty: Medium
// Pattern: DFS
// Time: O(n) | Space: O(h)
//
// Approach (Binary Tree, not just BST):
//   Post-order DFS. At each node:
//   - If node is null → return null.
//   - If node == p or node == q → return node (found one target).
//   - Recurse left and right.
//   - If both sides return non-null → current node is the LCA.
//   - Else return whichever side is non-null.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;  // p in one subtree, q in other
        return left ? left : right;
    }
};

int main() {
    Solution sol;
    //         3
    //        / \
    //       5   1
    //      / \ / \
    //     6  2 0  8
    //       / \
    //      7   4
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(5);
    r->right = new TreeNode(1);
    r->left->left = new TreeNode(6);
    r->left->right = new TreeNode(2);
    r->right->left = new TreeNode(0);
    r->right->right = new TreeNode(8);
    r->left->right->left = new TreeNode(7);
    r->left->right->right = new TreeNode(4);

    TreeNode* p = r->left;        // node 5
    TreeNode* q = r->right;       // node 1
    cout << sol.lowestCommonAncestor(r, p, q)->val << endl; // 3

    TreeNode* p2 = r->left;       // node 5
    TreeNode* q2 = r->left->right->right; // node 4
    cout << sol.lowestCommonAncestor(r, p2, q2)->val << endl; // 5

    cout << "All tests passed!" << endl;
    return 0;
}
