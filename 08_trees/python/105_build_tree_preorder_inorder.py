# LC#105 — Construct Binary Tree from Preorder and Inorder
# Difficulty: Medium | Pattern: Divide & Conquer + Map | Time: O(n) | Space: O(n)
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

def build_tree(pre, ino):
    pos = {v: i for i, v in enumerate(ino)}; it = iter(pre)
    def go(l, r):
        if l > r: return None
        n = TreeNode(next(it)); m = pos[n.val]
        n.left = go(l, m - 1); n.right = go(m + 1, r)
        return n
    return go(0, len(ino) - 1)

t = build_tree([3,9,20,15,7], [9,3,15,20,7]); assert (t.val, t.left.val, t.right.val) == (3, 9, 20)
