# LC#155 — Min Stack
# Difficulty: Medium | Pattern: Stack of (val, min) | Time: O(1) per op | Space: O(n)
class MinStack:
    def __init__(self): self.st = []
    def push(self, v): self.st.append((v, min(v, self.st[-1][1]) if self.st else v))
    def pop(self): self.st.pop()
    def top(self): return self.st[-1][0]
    def get_min(self): return self.st[-1][1]

s = MinStack(); s.push(-2); s.push(0); s.push(-3)
assert s.get_min() == -3; s.pop(); assert s.top() == 0 and s.get_min() == -2
