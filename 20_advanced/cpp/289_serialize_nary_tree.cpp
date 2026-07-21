// LC#428 — Serialize and Deserialize N-ary Tree
// Difficulty: Hard | Pattern: Preorder with child counts | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
struct Node { int val; vector<Node*> kids; Node(int v) : val(v) {} };
void ser(Node* n, string& s) { s += to_string(n->val) + "," + to_string(n->kids.size()) + ","; for (auto* k : n->kids) ser(k, s); }
string serialize(Node* r) { string s; if (r) ser(r, s); return s; }
Node* des(stringstream& ss) { string v, c; getline(ss, v, ','); getline(ss, c, ','); Node* n = new Node(stoi(v)); for (int i = stoi(c); i > 0; i--) n->kids.push_back(des(ss)); return n; }
Node* deserialize(string s) { if (s.empty()) return nullptr; stringstream ss(s); return des(ss); }
int main() { Node* r = new Node(1); r->kids = {new Node(3), new Node(2)}; r->kids[0]->kids = {new Node(5)}; string s = serialize(r); cout << s << " " << (serialize(deserialize(s)) == s) << endl; } // 1,2,3,1,5,0,2,0, 1
