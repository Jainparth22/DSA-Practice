/*
 * LC #102 — Binary Tree Level Order Traversal
 * Difficulty : Medium
 * Pattern    : BFS
 * Time       : O(n)
 * Space      : O(n) — queue holds at most one full level
 *
 * Approach:
 *   Standard BFS. At each iteration, process all nodes at current level
 *   (snapshot queue size before loop), collect values, enqueue children.
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left,*right; TreeNode(int x):val(x),left(nullptr),right(nullptr){} };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            result.push_back({});
            while (sz--) {
                auto node = q.front(); q.pop();
                result.back().push_back(node->val);
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    // Build [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left  = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left  = new TreeNode(15);
    root->right->right = new TreeNode(7);

    auto res = sol.levelOrder(root);
    // Expected: [[3],[9,20],[15,7]]
    for (auto& level : res) {
        for (int x : level) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
