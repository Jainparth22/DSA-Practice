// LC#588 — Design In-Memory File System
// Difficulty: Hard | Pattern: Trie of directories | Time: O(path) | Space: O(total)
#include <bits/stdc++.h>
using namespace std;
class FileSystem {
    struct Node { map<string, Node*> kids; string content; bool file = false; }; Node* root = new Node();
    Node* walk(const string& p, bool create) {
        Node* t = root; stringstream ss(p); string part;
        while (getline(ss, part, '/')) { if (part.empty()) continue; if (!t->kids.count(part)) t->kids[part] = new Node(); t = t->kids[part]; }
        return t;
    }
public:
    vector<string> ls(string p) {
        Node* t = walk(p, false); if (t->file) return {p.substr(p.rfind('/') + 1)};
        vector<string> r; for (auto& [k, v] : t->kids) r.push_back(k); return r;
    }
    void mkdir(string p) { walk(p, true); }
    void addContentToFile(string p, string c) { Node* t = walk(p, true); t->file = true; t->content += c; }
    string readContentFromFile(string p) { return walk(p, false)->content; }
};
int main() { FileSystem fs; fs.mkdir("/a/b/c"); fs.addContentToFile("/a/b/c/d", "hello"); cout << fs.ls("/")[0] << fs.readContentFromFile("/a/b/c/d") << endl; } // ahello
