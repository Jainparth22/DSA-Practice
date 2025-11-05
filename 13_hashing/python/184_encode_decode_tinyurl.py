# LC#535 — Encode and Decode TinyURL
# Difficulty: Medium | Pattern: Hash Map + counter | Time: O(1) | Space: O(n)
class Codec:
    BASE = "http://tinyurl.com/"
    def __init__(self): self.m = {}; self.id = 0
    def encode(self, url):
        key = str(self.id); self.id += 1; self.m[key] = url
        return self.BASE + key
    def decode(self, short): return self.m[short[len(self.BASE):]]

c = Codec(); assert c.decode(c.encode("https://leetcode.com/problems/design-tinyurl")) == "https://leetcode.com/problems/design-tinyurl"
