# LC#230 — Kth Smallest Element in a BST
# Difficulty: Medium | Pattern: Iterative Inorder | Time: O(h + k) | Space: O(h)
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

def kth_smallest(r, k):
    st = []
    while r or st:
        while r: st.append(r); r = r.left
        r = st.pop(); k -= 1
        if k == 0: return r.val
        r = r.right

assert kth_smallest(build([3,1,4,None,2]), 1) == 1 and kth_smallest(build([5,3,6,2,4,None,None,1]), 3) == 3
