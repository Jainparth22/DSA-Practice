// LC#212 — Word Search II
// Difficulty: Hard | Pattern: Trie + DFS | Time: O(mn * 4^L) | Space: O(total chars)
#include <bits/stdc++.h>
using namespace std;
struct T { T* c[26] = {}; string w; };
void dfs(vector<vector<char>>& b, int i, int j, T* t, vector<string>& res) {
    if (i < 0 || j < 0 || i >= (int)b.size() || j >= (int)b[0].size() || b[i][j] == '#' || !t->c[b[i][j] - 'a']) return;
    char ch = b[i][j]; t = t->c[ch - 'a'];
    if (!t->w.empty()) { res.push_back(t->w); t->w.clear(); }
    b[i][j] = '#'; dfs(b, i+1, j, t, res); dfs(b, i-1, j, t, res); dfs(b, i, j+1, t, res); dfs(b, i, j-1, t, res); b[i][j] = ch;
}
vector<string> findWords(vector<vector<char>>& b, vector<string>& words) {
    T* root = new T();
    for (auto& w : words) { T* t = root; for (char c : w) { if (!t->c[c - 'a']) t->c[c - 'a'] = new T(); t = t->c[c - 'a']; } t->w = w; }
    vector<string> res; for (int i = 0; i < (int)b.size(); i++) for (int j = 0; j < (int)b[0].size(); j++) dfs(b, i, j, root, res);
    return res;
}
int main() { vector<vector<char>> b = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}}; vector<string> w = {"oath","pea","eat","rain"}; cout << findWords(b, w).size() << endl; } // 2
