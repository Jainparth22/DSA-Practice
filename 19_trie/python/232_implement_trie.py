# LC#208 — Implement Trie (Prefix Tree)
# Difficulty: Medium
# Pattern: Trie Data Structure
# Time: O(L) insert/search/startsWith | Space: O(N*L)
#
# Approach:
#   Each node is a dict of children + an isEnd flag.
#   insert:      walk/create nodes char by char, set isEnd at last.
#   search:      walk nodes; return isEnd at last char.
#   startsWith:  walk nodes; True if full prefix path exists.

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                cur.children[ch] = TrieNode()
            cur = cur.children[ch]
        cur.is_end = True

    def search(self, word: str) -> bool:
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                return False
            cur = cur.children[ch]
        return cur.is_end

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for ch in prefix:
            if ch not in cur.children:
                return False
            cur = cur.children[ch]
        return True


if __name__ == "__main__":
    trie = Trie()
    trie.insert("apple")
    assert trie.search("apple") == True
    assert trie.search("app") == False
    assert trie.startsWith("app") == True
    trie.insert("app")
    assert trie.search("app") == True
    assert trie.startsWith("xyz") == False
    print("All tests passed!")
