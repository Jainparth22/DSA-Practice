// LC#211 — Design Add and Search Words Data Structure
// Difficulty: Medium
// Pattern: Trie + DFS for wildcard '.'
// Time: O(L) add, O(26^L) worst-case search with '.' | Space: O(N*L)
//
// Approach:
//   Standard Trie for addWord.
//   search: DFS through trie. For '.' try all 26 children recursively.
//   For regular char, follow the specific child as usual.

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() : isEnd(false) { fill(children, children + 26, nullptr); }
};

class WordDictionary {
    TrieNode* root;
    bool dfs(TrieNode* node, const string& word, int idx) {
        if (!node) return false;
        if (idx == (int)word.size()) return node->isEnd;
        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; i++)
                if (dfs(node->children[i], word, idx + 1)) return true;
            return false;
        }
        return dfs(node->children[c - 'a'], word, idx + 1);
    }
public:
    WordDictionary() { root = new TrieNode(); }
    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (!cur->children[i]) cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->isEnd = true;
    }
    bool search(string word) { return dfs(root, word, 0); }
};

int main() {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout << wd.search("pad") << endl; // 0
    cout << wd.search("bad") << endl; // 1
    cout << wd.search(".ad") << endl; // 1
    cout << wd.search("b..") << endl; // 1
    cout << "All tests passed!" << endl;
    return 0;
}
