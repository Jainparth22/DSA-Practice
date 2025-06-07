# LC#236 — Lowest Common Ancestor of a Binary Tree
# Difficulty: Medium
# Pattern: DFS (Post-order)
# Time: O(n) | Space: O(h)
#
# Approach:
#   If root is None or equals p or q → return root.
#   Recurse left and right.
#   If both sides return non-null → root is the LCA.
#   Otherwise return whichever side found something.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root or root is p or root is q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            return root
        return left or right


if __name__ == "__main__":
    s = Solution()

    r = TreeNode(3)
    r.left = TreeNode(5)
    r.right = TreeNode(1)
    r.left.left = TreeNode(6)
    r.left.right = TreeNode(2)
    r.right.left = TreeNode(0)
    r.right.right = TreeNode(8)
    r.left.right.left = TreeNode(7)
    r.left.right.right = TreeNode(4)

    assert s.lowestCommonAncestor(r, r.left, r.right).val == 3
    assert s.lowestCommonAncestor(r, r.left, r.left.right.right).val == 5

    print("All tests passed!")
