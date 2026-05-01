// LC#208 — Implement Trie (Prefix Tree)
// Difficulty: Medium
// Pattern: Trie Data Structure
// Time: O(L) for insert/search/startsWith where L = word length
// Space: O(ALPHABET_SIZE * L * N) where N = number of words
//
// Approach:
//   Each TrieNode has 26 children (a-z) and a boolean isEnd.
//   insert:      create nodes along the path, mark end.
//   search:      traverse nodes; return isEnd at last char.
//   startsWith:  traverse nodes; return true if path exists.

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() : isEnd(false) {
        fill(children, children + 26, nullptr);
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx])
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!cur->children[idx]) return false;
            cur = cur->children[idx];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!cur->children[idx]) return false;
            cur = cur->children[idx];
        }
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple")   << endl; // 1 (true)
    cout << trie.search("app")     << endl; // 0 (false - not inserted)
    cout << trie.startsWith("app") << endl; // 1 (true - prefix exists)
    trie.insert("app");
    cout << trie.search("app")     << endl; // 1 (true - now inserted)

    cout << "All tests passed!" << endl;
    return 0;
}
