// LC#98 — Validate Binary Search Tree
// Difficulty: Medium
// Pattern: DFS with valid range propagation
// Time: O(n) | Space: O(h)
//
// Approach:
//   Pass a [min, max] valid range to each node recursively.
//   Root starts with (-INF, +INF).
//   Going left:  update upper bound to current node's value.
//   Going right: update lower bound to current node's value.
//   If node->val is not strictly inside (min, max), return false.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true;
        if (node->val <= minVal || node->val >= maxVal) return false;
        return validate(node->left, minVal, node->val)
            && validate(node->right, node->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    Solution sol;
    //   2
    //  / \
    // 1   3
    TreeNode* r1 = new TreeNode(2);
    r1->left = new TreeNode(1);
    r1->right = new TreeNode(3);
    cout << sol.isValidBST(r1) << endl; // 1 (true)

    //   5
    //  / \
    // 1   4
    //    / \
    //   3   6
    TreeNode* r2 = new TreeNode(5);
    r2->left = new TreeNode(1);
    r2->right = new TreeNode(4);
    r2->right->left = new TreeNode(3);
    r2->right->right = new TreeNode(6);
    cout << sol.isValidBST(r2) << endl; // 0 (false, 4 < 5)

    cout << "All tests passed!" << endl;
    return 0;
}
