# LC #102 — Binary Tree Level Order Traversal
# Difficulty : Medium
# Pattern    : BFS
# Time       : O(n)   Space: O(n)

"""
BFS with queue. Snapshot queue size before each level to process exactly one level.
"""

from typing import Optional, List
from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val; self.left = left; self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        result, q = [], deque([root])
        while q:
            level = []
            for _ in range(len(q)):
                node = q.popleft()
                level.append(node.val)
                if node.left:  q.append(node.left)
                if node.right: q.append(node.right)
            result.append(level)
        return result


def n(v, l=None, r=None): return TreeNode(v, l, r)

if __name__ == "__main__":
    sol = Solution()

    t1 = n(3, n(9), n(20, n(15), n(7)))
    assert sol.levelOrder(t1) == [[3], [9, 20], [15, 7]]

    t2 = n(1)
    assert sol.levelOrder(t2) == [[1]]

    assert sol.levelOrder(None) == []

    t3 = n(1, n(2, n(4), n(5)), n(3, None, n(6)))
    assert sol.levelOrder(t3) == [[1], [2, 3], [4, 5, 6]]

    print("All tests passed!")
