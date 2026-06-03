# LC#307 — Range Sum Query - Mutable
# Difficulty: Medium | Pattern: Fenwick Tree (BIT) | Time: O(log n) | Space: O(n)
class NumArray:
    def __init__(self, nums):
        self.n = len(nums); self.a = [0] * self.n; self.bit = [0] * (self.n + 1)
        for i, v in enumerate(nums): self.update(i, v)
    def update(self, i, v):
        d = v - self.a[i]; self.a[i] = v; i += 1
        while i <= self.n: self.bit[i] += d; i += i & -i
    def sum_range(self, l, r): return self._pre(r + 1) - self._pre(l)
    def _pre(self, i):
        s = 0
        while i > 0: s += self.bit[i]; i -= i & -i
        return s

na = NumArray([1,3,5]); assert na.sum_range(0, 2) == 9; na.update(1, 2); assert na.sum_range(0, 2) == 8
