# LC#160 — Intersection of Two Linked Lists
# Difficulty: Easy | Pattern: Two Pointers | Time: O(m+n) | Space: O(1)
class ListNode:
    def __init__(self, val=0, next=None): self.val, self.next = val, next

def get_intersection_node(a, b):
    p, q = a, b
    while p is not q:
        p = p.next if p else b
        q = q.next if q else a
    return p

c = ListNode(8); a = ListNode(1, c); b = ListNode(2, c)
assert get_intersection_node(a, b) is c
