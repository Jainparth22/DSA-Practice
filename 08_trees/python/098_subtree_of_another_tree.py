# LC#572 — Subtree of Another Tree
# Difficulty: Easy | Pattern: DFS + Same Tree | Time: O(mn) | Space: O(h)
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

def is_subtree(r, s):
    def same(a, b):
        if not a or not b: return a is b
        return a.val == b.val and same(a.left, b.left) and same(a.right, b.right)
    if not r: return not s
    return same(r, s) or is_subtree(r.left, s) or is_subtree(r.right, s)

assert is_subtree(build([3,4,5,1,2]), build([4,1,2])) and not is_subtree(build([3,4,5,1,2,None,None,0]), build([4,1,2]))
