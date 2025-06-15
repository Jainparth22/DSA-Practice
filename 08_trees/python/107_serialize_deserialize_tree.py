# LC#297 — Serialize and Deserialize Binary Tree
# Difficulty: Hard | Pattern: Preorder with null markers | Time: O(n) | Space: O(n)
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

def serialize(t):
    out = []
    def go(n):
        if not n: out.append("#"); return
        out.append(str(n.val)); go(n.left); go(n.right)
    go(t)
    return ",".join(out)

def deserialize(s):
    it = iter(s.split(","))
    def go():
        v = next(it)
        if v == "#": return None
        n = TreeNode(int(v)); n.left = go(); n.right = go(); return n
    return go()

s = serialize(build([1,2,3,None,None,4,5])); assert serialize(deserialize(s)) == s
