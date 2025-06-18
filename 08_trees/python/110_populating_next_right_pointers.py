# LC#116 — Populating Next Right Pointers
# Difficulty: Medium | Pattern: Level pointers (perfect tree) | Time: O(n) | Space: O(1)
class Node:
    def __init__(self, val, left=None, right=None, nxt=None): self.val, self.left, self.right, self.next = val, left, right, nxt

def connect(root):
    lvl = root
    while lvl and lvl.left:
        c = lvl
        while c:
            c.left.next = c.right
            if c.next: c.right.next = c.next.left
            c = c.next
        lvl = lvl.left
    return root

b, c = Node(2), Node(3); a = Node(1, b, c); connect(a); assert b.next is c and c.next is None
