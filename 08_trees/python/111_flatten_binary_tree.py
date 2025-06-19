# LC#114 — Flatten Binary Tree to Linked List
# Difficulty: Medium | Pattern: Morris-style | Time: O(n) | Space: O(1)
from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None): self.val, self.left, self.right = val, left, right

def build(v):  # level-order, None = null
    if not v or v[0] is None: return None
    root = TreeNode(v[0]); q = deque([root]); i = 1
    while q and i < len(v):
        n = q.popleft()
        if i < len(v) and v[i] is not None: n.left = TreeNode(v[i]); q.append(n.left)
        i += 1
        if i < len(v) and v[i] is not None: n.right = TreeNode(v[i]); q.append(n.right)
        i += 1
    return root

def flatten(r):
    while r:
        if r.left:
            p = r.left
            while p.right: p = p.right
            p.right = r.right; r.right = r.left; r.left = None
        r = r.right

t = build([1,2,5,3,4,None,6]); flatten(t); out = []
while t: out.append(t.val); t = t.right
assert out == [1,2,3,4,5,6]
