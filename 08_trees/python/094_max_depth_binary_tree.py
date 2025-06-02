# LC #104 — Maximum Depth of Binary Tree
# Difficulty : Easy
# Pattern    : DFS
# Time       : O(n)   Space: O(h)

"""
Recursive: depth = 1 + max(depth(left), depth(right)), base: None → 0
Iterative: BFS, count levels.
"""

from typing import Optional
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val; self.left = left; self.right = right


class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))

    def maxDepthBFS(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        q, depth = deque([root]), 0
        while q:
            depth += 1
            for _ in range(len(q)):
                node = q.popleft()
                if node.left:  q.append(node.left)
                if node.right: q.append(node.right)
        return depth


def n(v, l=None, r=None): return TreeNode(v, l, r)

if __name__ == "__main__":
    sol = Solution()
    t1 = n(3, n(9), n(20, n(15), n(7)))
    t2 = n(1, None, n(2))

    for fn in [sol.maxDepth, sol.maxDepthBFS]:
        assert fn(t1) == 3
        assert fn(t2) == 2
        assert fn(None) == 0
        assert fn(n(1)) == 1
    print("All tests passed!")
