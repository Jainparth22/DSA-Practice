# LC#876 — Middle of the Linked List
# Difficulty: Easy | Pattern: Slow/Fast Pointers | Time: O(n) | Space: O(1)
class ListNode:
    def __init__(self, val=0, next=None): self.val, self.next = val, next

def build(v):
    d = t = ListNode()
    for x in v: t.next = ListNode(x); t = t.next
    return d.next

def middle_node(h):
    s = f = h
    while f and f.next: s, f = s.next, f.next.next
    return s

assert middle_node(build([1,2,3,4,5,6])).val == 4
