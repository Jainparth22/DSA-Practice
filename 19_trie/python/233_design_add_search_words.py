# LC#211 — Design Add and Search Words Data Structure
# Difficulty: Medium
# Pattern: Trie + DFS for wildcard '.'
# Time: O(L) add, O(26^L) worst search | Space: O(N*L)
#
# Approach:
#   Standard Trie addWord.
#   search: DFS — if char is '.', try all children recursively.
#   Otherwise follow the exact child.

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False


class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                cur.children[ch] = TrieNode()
            cur = cur.children[ch]
        cur.is_end = True

    def search(self, word: str) -> bool:
        def dfs(node: TrieNode, idx: int) -> bool:
            if idx == len(word):
                return node.is_end
            ch = word[idx]
            if ch == '.':
                return any(dfs(child, idx + 1) for child in node.children.values())
            if ch not in node.children:
                return False
            return dfs(node.children[ch], idx + 1)

        return dfs(self.root, 0)


if __name__ == "__main__":
    wd = WordDictionary()
    wd.addWord("bad")
    wd.addWord("dad")
    wd.addWord("mad")
    assert wd.search("pad") == False
    assert wd.search("bad") == True
    assert wd.search(".ad") == True
    assert wd.search("b..") == True
    assert wd.search("....") == False
    print("All tests passed!")
