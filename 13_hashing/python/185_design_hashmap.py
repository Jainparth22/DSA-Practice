# LC#706 — Design HashMap
# Difficulty: Easy | Pattern: Chaining buckets | Time: O(1) avg | Space: O(n)
class MyHashMap:
    B = 1009
    def __init__(self): self.t = [[] for _ in range(self.B)]
    def put(self, k, v):
        for p in self.t[k % self.B]:
            if p[0] == k: p[1] = v; return
        self.t[k % self.B].append([k, v])
    def get(self, k):
        for p in self.t[k % self.B]:
            if p[0] == k: return p[1]
        return -1
    def remove(self, k): self.t[k % self.B] = [p for p in self.t[k % self.B] if p[0] != k]

m = MyHashMap(); m.put(1, 1); m.put(1, 2); assert m.get(1) == 2 and m.get(3) == -1; m.remove(1); assert m.get(1) == -1
