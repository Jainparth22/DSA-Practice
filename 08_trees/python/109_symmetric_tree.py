# LC#101 — Symmetric Tree
# Difficulty: Easy | Pattern: DFS mirror | Time: O(n) | Space: O(h)
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

def is_symmetric(t):
    def mirror(a, b):
        if not a or not b: return a is b
        return a.val == b.val and mirror(a.left, b.right) and mirror(a.right, b.left)
    return not t or mirror(t.left, t.right)

assert is_symmetric(build([1,2,2,3,4,4,3])) and not is_symmetric(build([1,2,2,None,3,None,3]))
