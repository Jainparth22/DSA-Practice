# LC #226 — Invert Binary Tree
# Difficulty : Easy
# Pattern    : DFS (recursive)
# Time       : O(n)   Space: O(h)

"""
Recursively invert both subtrees, then swap left and right children.
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val; self.left = left; self.right = right


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        left  = self.invertTree(root.left)
        right = self.invertTree(root.right)
        root.left, root.right = right, left
        return root


def build(vals):
    if not vals: return None
    root = TreeNode(vals[0])
    q = deque([root])
    i = 1
    while q and i < len(vals):
        node = q.popleft()
        if i < len(vals):
            node.left = TreeNode(vals[i]); q.append(node.left); i += 1
        if i < len(vals):
            node.right = TreeNode(vals[i]); q.append(node.right); i += 1
    return root

def level_order(root):
    if not root: return []
    q, res = deque([root]), []
    while q:
        node = q.popleft(); res.append(node.val)
        if node.left:  q.append(node.left)
        if node.right: q.append(node.right)
    return res


if __name__ == "__main__":
    sol = Solution()
    assert level_order(sol.invertTree(build([4,2,7,1,3,6,9]))) == [4,7,2,9,6,3,1]
    assert level_order(sol.invertTree(build([2,1,3])))          == [2,3,1]
    assert sol.invertTree(None) is None
    print("All tests passed!")
