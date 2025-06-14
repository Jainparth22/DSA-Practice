# LC#124 — Binary Tree Maximum Path Sum
# Difficulty: Hard | Pattern: DFS gain | Time: O(n) | Space: O(h)
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

def max_path_sum(t):
    best = [float("-inf")]
    def gain(n):
        if not n: return 0
        l, r = max(0, gain(n.left)), max(0, gain(n.right))
        best[0] = max(best[0], n.val + l + r)
        return n.val + max(l, r)
    gain(t)
    return best[0]

assert max_path_sum(build([-10,9,20,None,None,15,7])) == 42
