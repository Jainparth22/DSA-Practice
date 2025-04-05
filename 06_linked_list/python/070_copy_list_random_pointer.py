# LC#138 — Copy List with Random Pointer
# Difficulty: Medium | Pattern: Hash Map | Time: O(n) | Space: O(n)
class Node:
    def __init__(self, val, next=None, random=None): self.val, self.next, self.random = val, next, random

def copy_random_list(h):
    m = {None: None}; c = h
    while c: m[c] = Node(c.val); c = c.next
    c = h
    while c: m[c].next = m[c.next]; m[c].random = m[c.random]; c = c.next
    return m[h]

a, b = Node(1), Node(2); a.next = b; a.random = b; b.random = b
c = copy_random_list(a); assert c is not a and c.random.val == 2 and c.next.random is c.next
