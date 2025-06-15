// LC#297 — Serialize and Deserialize Binary Tree
// Difficulty: Hard | Pattern: Preorder with null markers | Time: O(n) | Space: O(n)
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
void ser(TreeNode* t, string& s) { if (!t) { s += "#,"; return; } s += to_string(t->val) + ","; ser(t->left, s); ser(t->right, s); }
string serialize(TreeNode* t) { string s; ser(t, s); return s; }
TreeNode* des(stringstream& ss) {
    string tok; getline(ss, tok, ',');
    if (tok == "#") return nullptr;
    TreeNode* n = new TreeNode(stoi(tok)); n->left = des(ss); n->right = des(ss); return n;
}
TreeNode* deserialize(string s) { stringstream ss(s); return des(ss); }
int main() { string s = serialize(build({1,2,3,N,N,4,5})); cout << s << " " << (serialize(deserialize(s)) == s) << endl; } // 1,2,#,#,3,4,#,#,5,#,#, 1
