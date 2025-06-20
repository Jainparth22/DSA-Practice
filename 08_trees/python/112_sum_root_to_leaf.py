# LC#129 — Sum Root to Leaf Numbers
# Difficulty: Medium | Pattern: DFS | Time: O(n) | Space: O(h)
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

def sum_numbers(t, cur=0):
    if not t: return 0
    cur = cur * 10 + t.val
    if not t.left and not t.right: return cur
    return sum_numbers(t.left, cur) + sum_numbers(t.right, cur)

assert sum_numbers(build([4,9,0,5,1])) == 1026
