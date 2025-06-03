# LC#543 — Diameter of Binary Tree
# Difficulty: Easy
# Pattern: DFS / Tree Recursion
# Time: O(n) | Space: O(h)
#
# Approach:
#   Recursively compute height of each subtree.
#   At each node, diameter candidate = left_height + right_height.
#   Track the global maximum.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.diameter = 0

        def height(node):
            if not node:
                return 0
            left = height(node.left)
            right = height(node.right)
            self.diameter = max(self.diameter, left + right)
            return 1 + max(left, right)

        height(root)
        return self.diameter


if __name__ == "__main__":
    s = Solution()

    root = TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))
    assert s.diameterOfBinaryTree(root) == 3

    r2 = TreeNode(1, TreeNode(2))
    assert s.diameterOfBinaryTree(r2) == 1

    assert s.diameterOfBinaryTree(TreeNode(1)) == 0

    print("All tests passed!")
