# LC#112 — Path Sum
# Difficulty: Easy | Pattern: DFS | Time: O(n) | Space: O(h)
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

def has_path_sum(t, s):
    if not t: return False
    if not t.left and not t.right: return t.val == s
    return has_path_sum(t.left, s - t.val) or has_path_sum(t.right, s - t.val)

assert has_path_sum(build([5,4,8,11,None,13,4,7,2,None,None,None,1]), 22)
