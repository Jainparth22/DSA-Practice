# LC#110 — Balanced Binary Tree
# Difficulty: Easy | Pattern: DFS height | Time: O(n) | Space: O(h)
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

def is_balanced(t):
    def h(n):
        if not n: return 0
        l, r = h(n.left), h(n.right)
        return -1 if l < 0 or r < 0 or abs(l - r) > 1 else 1 + max(l, r)
    return h(t) >= 0

assert is_balanced(build([3,9,20,None,None,15,7])) and not is_balanced(build([1,2,2,3,3,None,None,4,4]))
