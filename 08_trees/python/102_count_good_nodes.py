# LC#1448 — Count Good Nodes in Binary Tree
# Difficulty: Medium | Pattern: DFS with running max | Time: O(n) | Space: O(h)
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

def good_nodes(t, mx=float("-inf")):
    if not t: return 0
    return (t.val >= mx) + good_nodes(t.left, max(mx, t.val)) + good_nodes(t.right, max(mx, t.val))

assert good_nodes(build([3,1,4,3,None,1,5])) == 4
