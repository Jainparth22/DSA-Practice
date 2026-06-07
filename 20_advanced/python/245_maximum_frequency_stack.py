# LC#895 — Maximum Frequency Stack
# Difficulty: Hard | Pattern: Frequency -> Stack map | Time: O(1) per op | Space: O(n)
from collections import defaultdict

class FreqStack:
    def __init__(self): self.cnt = defaultdict(int); self.groups = defaultdict(list); self.maxf = 0
    def push(self, x):
        self.cnt[x] += 1; f = self.cnt[x]; self.maxf = max(self.maxf, f); self.groups[f].append(x)
    def pop(self):
        x = self.groups[self.maxf].pop()
        if not self.groups[self.maxf]: self.maxf -= 1
        self.cnt[x] -= 1
        return x

s = FreqStack()
for x in (5,7,5,7,4,5): s.push(x)
assert [s.pop() for _ in range(4)] == [5,7,5,4]
