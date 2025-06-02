/*
 * LC #104 — Maximum Depth of Binary Tree
 * Difficulty : Easy
 * Pattern    : DFS (returns height)
 * Time       : O(n)
 * Space      : O(h)
 *
 * Approach:
 *   height(node) = 1 + max(height(left), height(right))
 *   height(null) = 0
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode { int val; TreeNode *left, *right; TreeNode(int x):val(x),left(nullptr),right(nullptr){} };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // Iterative — BFS level count
    int maxDepthBFS(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            depth++;
            int sz = q.size();
            while (sz--) {
                auto node = q.front(); q.pop();
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return depth;
    }
};

TreeNode* build(vector<int> v) {
    if (v.empty()) return nullptr;
    TreeNode* root = new TreeNode(v[0]);
    queue<TreeNode*> q; q.push(root); int i=1;
    while (!q.empty() && i<(int)v.size()) {
        auto n=q.front(); q.pop();
        if(i<(int)v.size()){n->left=new TreeNode(v[i++]);q.push(n->left);}
        if(i<(int)v.size()){n->right=new TreeNode(v[i++]);q.push(n->right);}
    }
    return root;
}

int main() {
    Solution sol;
    cout << sol.maxDepth(build({3,9,20,0,0,15,7})) << "\n"; // 3
    cout << sol.maxDepth(build({1,0,0,2}))           << "\n"; // 3? No: build gives [1,null,2] → 2
    cout << sol.maxDepth(nullptr)                    << "\n"; // 0
    cout << sol.maxDepth(build({1}))                 << "\n"; // 1
    return 0;
}
