# LC#677 — Map Sum Pairs
# Difficulty: Medium | Pattern: Trie with sums | Time: O(L) | Space: O(total chars)
class MapSum:
    def __init__(self): self.root = {}; self.kv = {}
    def insert(self, key, val):
        delta = val - self.kv.get(key, 0); self.kv[key] = val; t = self.root
        for c in key:
            t = t.setdefault(c, {}); t["#"] = t.get("#", 0) + delta
    def sum(self, prefix):
        t = self.root
        for c in prefix:
            if c not in t: return 0
            t = t[c]
        return t.get("#", 0)

m = MapSum(); m.insert("apple", 3); assert m.sum("ap") == 3; m.insert("app", 2); assert m.sum("ap") == 5
