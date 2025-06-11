# LC#98 — Validate Binary Search Tree
# Difficulty: Medium
# Pattern: DFS with Range Propagation
# Time: O(n) | Space: O(h)
#
# Approach:
#   Each node must fall strictly within (min_val, max_val).
#   Pass updated bounds left (upper=node.val) and right (lower=node.val).

import math


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def validate(node, min_val, max_val):
            if not node:
                return True
            if node.val <= min_val or node.val >= max_val:
                return False
            return (validate(node.left, min_val, node.val) and
                    validate(node.right, node.val, max_val))

        return validate(root, -math.inf, math.inf)


if __name__ == "__main__":
    s = Solution()

    r1 = TreeNode(2, TreeNode(1), TreeNode(3))
    assert s.isValidBST(r1) == True

    r2 = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
    assert s.isValidBST(r2) == False

    # Edge: single node
    assert s.isValidBST(TreeNode(1)) == True

    print("All tests passed!")
