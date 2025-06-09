# LC#199 — Binary Tree Right Side View
# Difficulty: Medium | Pattern: BFS level order | Time: O(n) | Space: O(w)
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

def right_side_view(r):
    res = []; q = deque([r] if r else [])
    while q:
        res.append(q[-1].val)
        for _ in range(len(q)):
            n = q.popleft()
            if n.left: q.append(n.left)
            if n.right: q.append(n.right)
    return res

assert right_side_view(build([1,2,3,None,5,None,4])) == [1, 3, 4]
