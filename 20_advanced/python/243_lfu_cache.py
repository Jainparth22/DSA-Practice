# LC#460 — LFU Cache
# Difficulty: Hard | Pattern: Hash Maps + Frequency Buckets | Time: O(1) per op | Space: O(capacity)
from collections import defaultdict, OrderedDict

class LFUCache:
    def __init__(self, capacity):
        self.cap = capacity; self.minf = 0; self.kv = {}; self.freq = defaultdict(OrderedDict)
    def _touch(self, k):
        v, f = self.kv[k]; del self.freq[f][k]
        if not self.freq[f] and self.minf == f: self.minf += 1
        self.kv[k] = (v, f + 1); self.freq[f + 1][k] = None
    def get(self, k):
        if k not in self.kv: return -1
        self._touch(k); return self.kv[k][0]
    def put(self, k, v):
        if not self.cap: return
        if k in self.kv:
            self.kv[k] = (v, self.kv[k][1]); self._touch(k); return
        if len(self.kv) == self.cap:
            ev, _ = self.freq[self.minf].popitem(last=False); del self.kv[ev]
        self.kv[k] = (v, 1); self.minf = 1; self.freq[1][k] = None

c = LFUCache(2); c.put(1, 1); c.put(2, 2); c.get(1); c.put(3, 3)
assert c.get(2) == -1 and c.get(3) == 3
