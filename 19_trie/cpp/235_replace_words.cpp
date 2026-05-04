// LC#648 — Replace Words
// Difficulty: Medium | Pattern: Trie | Time: O(total chars) | Space: O(dict chars)
#include <bits/stdc++.h>
using namespace std;
struct T { T* c[26] = {}; bool end = false; };
string replaceWords(vector<string>& dict, string s) {
    T* root = new T();
    for (auto& w : dict) { T* t = root; for (char c : w) { if (!t->c[c - 'a']) t->c[c - 'a'] = new T(); t = t->c[c - 'a']; } t->end = true; }
    stringstream ss(s); string w, out;
    while (ss >> w) {
        T* t = root; string pre; bool found = false;
        for (char c : w) { if (!t->c[c - 'a']) break; t = t->c[c - 'a']; pre += c; if (t->end) { found = true; break; } }
        out += (out.empty() ? "" : " ") + (found ? pre : w);
    }
    return out;
}
int main() { vector<string> d = {"cat","bat","rat"}; cout << replaceWords(d, "the cattle was rattled by the battery") << endl; } // the cat was rat by the bat
